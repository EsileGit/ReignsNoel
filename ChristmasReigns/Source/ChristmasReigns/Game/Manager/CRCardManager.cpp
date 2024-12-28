// Fill out your copyright notice in the Description page of Project Settings.


#include "CRCardManager.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"

#include "ChristmasReigns/LogChannel.h"
#include "ChristmasReigns/DataStructure/CardsInfo.h"
#include "ChristmasReigns/GameplayAbilitySystem/Library/CRAbilitySystemLibrary.h"
#include "ChristmasReigns/UI/WidgetController/OverlayWidgetController.h"

//----------------------------------------------------------------------------------------------------------------------
void UCRCardManager::OnOverlayWCSetup()
{
	OverlayWC = UCRAbilitySystemLibrary::GetOverlayWidgetController(GetWorld());
	CardsInfo = OverlayWC->ModifyCardsInfo();
}

//----------------------------------------------------------------------------------------------------------------------
FCRCardInfo UCRCardManager::GetNextCardFromChoice(FCRChoiceInfo const& choiceInfo) const
{
	if(choiceInfo.NextCardIDs.IsEmpty())
	{
		UE_LOG(LogCR, Warning, TEXT("No next card in choice list of choice %s"), *choiceInfo.TextToDisplay.ToString());
		return FCRCardInfo();
	}
	const int32 randomIndex = FMath::RandRange(0, choiceInfo.NextCardIDs.Num() - 1);
	const FCardIDType ID = choiceInfo.NextCardIDs[randomIndex];

	return CardsInfo->GetCardInfoForID(ID);
}

//----------------------------------------------------------------------------------------------------------------------
void UCRCardManager::ApplyChoice(FCRChoiceInfo const& choiceInfo, UAbilitySystemComponent* pAbilitySystem) const
{

	if (!choiceInfo.EffectToApplyOnChoice)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameplayEffectClass of %s is invalid!"), *choiceInfo.TextToDisplay.ToString());
		return;
	}

	if (!pAbilitySystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Ability System Component found on actor!"));
		return;
	}

	// Create an effect context for the actor (self-cast)
	FGameplayEffectContextHandle EffectContext = pAbilitySystem->MakeEffectContext();
	EffectContext.AddSourceObject(pAbilitySystem);

	// Create a spec handle for the gameplay effect
	FGameplayEffectSpecHandle SpecHandle = pAbilitySystem->MakeOutgoingSpec(choiceInfo.EffectToApplyOnChoice, 1.0f, EffectContext);

	if (SpecHandle.IsValid())
	{
		pAbilitySystem->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		UE_LOG(LogTemp, Log, TEXT("Applied GameplayEffect to self!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create a valid GameplayEffectSpecHandle!"));
	}
}
