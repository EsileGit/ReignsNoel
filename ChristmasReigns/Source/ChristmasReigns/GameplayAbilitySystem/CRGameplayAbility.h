// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CRGameplayAbility.generated.h"

// *********************************************************************************************************************
UENUM(BlueprintType)
enum class EAbilityInputID : uint8
{
	None,
	Confirm,
	Cancel,
	FireAbility
};

// *********************************************************************************************************************
/**
 * not too sure I will need this, but in case...
 */
UCLASS()
class CHRISTMASREIGNS_API UCRGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, category = Ability)
	EAbilityInputID AbilityInputID;

	EAbilityInputID GetAbilityInputID() const { return AbilityInputID; }
};
