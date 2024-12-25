// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"

#include "Engine/DataAsset.h"
#include "AttributeInfo.generated.h"

class UCRAttributeSetBase;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct FCRAttributeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AttributeTag {};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeName {};
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeDescription {};

	UPROPERTY(BlueprintReadOnly)
	float AttributeValue = 0;

	UPROPERTY(BlueprintReadOnly)
	float AttributeMaxValue = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayAttribute Attribute {};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bHasAMax {false};
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bHasAMax", EditConditionHides))
	FGameplayAttribute MaxAttribute {};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bHasAMax", EditConditionHides))
	TSubclassOf<UGameplayEffect> MaxAttributeEffect;
};

/**
 * General information for each attribute
 */
UCLASS()
class CHRISTMASREIGNS_API UAttributeInfo : public UDataAsset
{
	GENERATED_BODY()
public:
	FCRAttributeInfo FindAttributeInfoForTag(FGameplayTag const& attributeTag, bool bLogNotFound=false) const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty="{AttributeName}"))
	TArray<FCRAttributeInfo> AttributeInfos;
};
