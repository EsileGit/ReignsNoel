// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CRWidgetController.generated.h"

class UAttributeSet;
class UCRAttributeSet;
class UAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()
	FWidgetControllerParams(){}
	FWidgetControllerParams(TObjectPtr<APlayerController> const& playerController, TObjectPtr<APlayerState> const& playerState,
		TObjectPtr<UAbilitySystemComponent> const& abilitySystemComponent, TObjectPtr<UAttributeSet> const& attributeSet):
	PlayerController(playerController),
	PlayerState(playerState),
	AbilitySystemComponent(abilitySystemComponent),
	AttributeSet(attributeSet)
	{}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};


/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CHRISTMASREIGNS_API UCRWidgetController : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void SetWidgetControllerParams(FWidgetControllerParams const& WCParams);
	
	UFUNCTION(BlueprintCallable)
	virtual void BroadcastInitialValues() const {}
	virtual void BindCallbacksToDependencies() const {}
	UFUNCTION(BlueprintCallable)
	virtual void UnbindAllDelegates() {}

	UCRAttributeSet* ModifyCRAttributeSet();
	
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController;
	
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState;
	
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;

	/* Cast versions */
	TObjectPtr<UCRAttributeSet> CRAttributeSet;
	//TObjectPtr<UCRAttributeSet> CRAttributeSet;
	
};
