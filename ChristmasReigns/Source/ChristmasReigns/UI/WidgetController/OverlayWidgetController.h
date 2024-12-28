// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CRWidgetController.h"

#include "ChristmasReigns/DataStructure/CardsInfo.h"
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
	virtual void BindCallbacksToDependencies() const override;
	virtual void SetWidgetControllerParams(FWidgetControllerParams const& WCParams) override;

	/** FLOW **/
	UFUNCTION(BlueprintCallable)
	void OnChoiceSelected(bool isLeftChoice);
	UFUNCTION(BlueprintCallable)
	void OnChoiceHovered(bool isLeftChoice);
	
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

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCardsInfo> CardsInfos;
	
	FCRCardInfo CurrentCardDisplayed;
};
