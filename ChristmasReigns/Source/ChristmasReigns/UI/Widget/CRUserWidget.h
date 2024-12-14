// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CRUserWidget.generated.h"
// BlueprintType is to use the Struct in a blueprint
USTRUCT(BlueprintType)
struct FGaugeData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	float Percent {0.f};

	UPROPERTY(BlueprintReadOnly)
	bool bIsVisible {false};
};


/**
 * Base class for all widgets in reigns
 */
UCLASS()
class CHRISTMASREIGNS_API UCRUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Gauge")
	FGaugeData GetGaugeData();
};
