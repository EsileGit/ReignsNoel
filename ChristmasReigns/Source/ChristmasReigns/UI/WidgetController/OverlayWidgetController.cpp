// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayWidgetController.h"

#include "ChristmasReigns/LogChannel.h"
#include "ChristmasReigns/Game/Manager/CRCardManager.h"
#include "ChristmasReigns/GameplayAbilitySystem/AttributeSet/CRAttributeSet.h"


//----------------------------------------------------------------------------------------------------------------------
void UOverlayWidgetController::BroadcastInitialValues() const
{
	Super::BroadcastInitialValues();
	
	if (UCRAttributeSet const* pAttributeSet =  Cast<UCRAttributeSet>(AttributeSet))
	{
		OnMentalChanged.Broadcast(pAttributeSet->GetMental());
		OnMaxMentalChanged.Broadcast(pAttributeSet->GetMaxMental());
		OnPopularityChanged.Broadcast(pAttributeSet->GetPopularity());
		OnMaxPopularityChanged.Broadcast(pAttributeSet->GetMaxPopularity());
		OnMotherPrideChanged.Broadcast(pAttributeSet->GetMotherPride());
		OnMaxMotherPrideChanged.Broadcast(pAttributeSet->GetMaxMotherPride());
		
		BroadcastCurrentCardInfos();
	}
}

//----------------------------------------------------------------------------------------------------------------------
void UOverlayWidgetController::BindCallbacksToDependencies() const
{
	Super::BindCallbacksToDependencies();
	UCRAttributeSet const* pAttributeSet = Cast<UCRAttributeSet>(AttributeSet);
	if (!pAttributeSet)
		return;
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(pAttributeSet->GetMentalAttribute()).
	AddLambda([this](FOnAttributeChangeData const& data){OnMentalChanged.Broadcast(data.NewValue);} );
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(pAttributeSet->GetMaxMentalAttribute()).
		AddLambda([this](FOnAttributeChangeData const& data){OnMaxMentalChanged.Broadcast(data.NewValue);} );
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(pAttributeSet->GetPopularityAttribute()).
	AddLambda([this](FOnAttributeChangeData const& data){OnPopularityChanged.Broadcast(data.NewValue);} );
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(pAttributeSet->GetMaxPopularityAttribute()).
		AddLambda([this](FOnAttributeChangeData const& data){OnMaxPopularityChanged.Broadcast(data.NewValue);} );
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(pAttributeSet->GetMotherPrideAttribute()).
	AddLambda([this](FOnAttributeChangeData const& data){OnMotherPrideChanged.Broadcast(data.NewValue);} );
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(pAttributeSet->GetMaxMotherPrideAttribute()).
		AddLambda([this](FOnAttributeChangeData const& data){OnMaxMotherPrideChanged.Broadcast(data.NewValue);} );
}

//----------------------------------------------------------------------------------------------------------------------
void UOverlayWidgetController::SetWidgetControllerParams(FWidgetControllerParams const& WCParams)
{
	Super::SetWidgetControllerParams(WCParams);

	checkf(CardsInfos, TEXT("CardsInfo asset has not been referenced in OverlayWidgetController"));
	CurrentCardDisplayed = CardsInfos->CardsList[0];

	if (UCRCardManager* pCardsManager = GetWorld()->GetSubsystem<UCRCardManager>())
	{
		pCardsManager->OnOverlayWCSetup();
	}
}

//----------------------------------------------------------------------------------------------------------------------
void UOverlayWidgetController::OnChoiceSelected(bool isLeftChoice)
{
	UE_LOG(LogCR, Log, TEXT("Choosed card %s"), *CurrentCardDisplayed.CardIDName.ToString());
	
	if (UCRCardManager* pCardsManager = GetWorld()->GetSubsystem<UCRCardManager>())
	{
		FCRChoiceInfo const& choice = isLeftChoice ? CurrentCardDisplayed.LeftChoice : CurrentCardDisplayed.RightChoice;
		pCardsManager->ApplyChoice(choice, AbilitySystemComponent);
		CurrentCardDisplayed = pCardsManager->GetNextCardFromChoice(choice);
		BroadcastCurrentCardInfos();
	}
	
}

//----------------------------------------------------------------------------------------------------------------------
void UOverlayWidgetController::OnChoiceHovered(bool isLeftChoice)
{
	UE_LOG(LogCR, Log, TEXT("Hovered card %s"), *CurrentCardDisplayed.CardIDName.ToString());
}

//----------------------------------------------------------------------------------------------------------------------
void UOverlayWidgetController::BroadcastCurrentCardInfos() const
{
	OnCardInfoDelegate.Broadcast(CurrentCardDisplayed);
}
