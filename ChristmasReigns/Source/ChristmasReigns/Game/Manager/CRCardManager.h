// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CRCardManager.generated.h"

struct FCRChoiceInfo;
struct FCRCardInfo;
class UCardsInfo;
class UOverlayWidgetController;
class UAbilitySystemComponent;
/**
 * A manager to handle flow decisions related to cards
 */
UCLASS()
class CHRISTMASREIGNS_API UCRCardManager : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	void OnOverlayWCSetup();

	/** FLOW **/
	FCRCardInfo GetNextCardFromChoice(FCRChoiceInfo const& choiceInfo) const;
	void ApplyChoice(FCRChoiceInfo const& choiceInfo, UAbilitySystemComponent* pAbilitySystem) const;

private:
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWC;
	UPROPERTY()
	TObjectPtr<UCardsInfo> CardsInfo;
};
