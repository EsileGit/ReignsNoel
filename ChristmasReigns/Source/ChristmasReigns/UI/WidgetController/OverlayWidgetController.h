// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CRWidgetController.h"

#include "ChristmasReigns/Game/Tool/DelegateTypes.h"

#include "OverlayWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class CHRISTMASREIGNS_API UOverlayWidgetController : public UCRWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() const override;
	
private:
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeModifiedSignature OnMentalChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeModifiedSignature OnMaxMentalChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeModifiedSignature OnPopularityChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeModifiedSignature OnMaxPopularityChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeModifiedSignature OnMotherPrideChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeModifiedSignature OnMaxMotherPrideChanged;
};
