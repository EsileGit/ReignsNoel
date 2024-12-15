// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SingleCard.generated.h"

/**
 * 
 */
UCLASS()
class CHRISTMASREIGNS_API USingleCard : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	FString CardDebugName {"NoName"};
	
	UPROPERTY(EditDefaultsOnly)
	FText CardMainText;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UTexture2D> CardImage;
};
