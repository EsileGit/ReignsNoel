// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayWidgetController.h"

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
