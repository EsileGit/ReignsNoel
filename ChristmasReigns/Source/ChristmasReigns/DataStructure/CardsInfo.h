// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "CardsInfo.generated.h"

class UGameplayEffect;
struct FCRCardInfo;

/**
 * How the ID of a ard is defined
 */
USTRUCT(BlueprintType)
struct FCardIDType
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FString Name;
};

/**
 * One choice of a card
 */
USTRUCT(BlueprintType, DisplayName="{TextToDisplay}")
struct FCRChoiceInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	FText TextToDisplay;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> EffectToApplyOnChoice;

	UPROPERTY(EditDefaultsOnly, meta=(TitleProperty="{Name}"))
	TArray<FCardIDType> NextCardIDs {};
};

/**
 * One card and its data
 */
USTRUCT(BlueprintType)
struct FCRCardInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FCardIDType CardIDName {""};
	
	UPROPERTY(EditDefaultsOnly)
	FString CharacterName {""};

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UTexture2D> CardImage;

	UPROPERTY(EditDefaultsOnly)
	FText CardMainText;
	
	UPROPERTY(EditDefaultsOnly, Category=Flow)
	FCRChoiceInfo LeftChoice;

	UPROPERTY(EditDefaultsOnly, Category=Flow)
	FCRChoiceInfo RightChoice;

	UPROPERTY(EditDefaultsOnly, Category=Flow)
	bool bIsBeginning {false};
};

/**
 * Table of all cards
 */
UCLASS()
class CHRISTMASREIGNS_API UCardsInfo : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty="{CardIDName}"))
	TArray<FCRCardInfo> CardsList;
};
