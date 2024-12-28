// Fill out your copyright notice in the Description page of Project Settings.


#include "CRCardManager.h"

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
