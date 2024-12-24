// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CRAbilitySystemLibrary.generated.h"

/**
 * Lib for GAS related stuff
 */
UCLASS()
class CHRISTMASREIGNS_API UCRAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/** Widget controller getters **/
	UFUNCTION(BlueprintPure, Category="Reigns AbilitySystemLibrary|WidgetController", meta=(DefaultToSelf = "worldContextObject"))
	static UOverlayWidgetController* GetOverlayWidgetController(UObject const* worldContextObject);
};
