// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CRHud.generated.h"

class UCRUserWidget;
/**
 * 
 */
UCLASS()
class CHRISTMASREIGNS_API ACRHud : public AHUD
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void InitOverlay();
	
private:
	UPROPERTY()
	TObjectPtr<UCRUserWidget> OverlayWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> OverlayWidgetClass;
};
