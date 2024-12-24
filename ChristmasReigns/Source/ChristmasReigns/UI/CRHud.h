// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CRHud.generated.h"

class UCRUserWidget;
class UOverlayWidgetController;
struct FWidgetControllerParams;
class UUserWidget;
/**
 * 
 */
UCLASS()
class CHRISTMASREIGNS_API ACRHud : public AHUD
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	UOverlayWidgetController* GetOrCreateOverlayWidgetController(FWidgetControllerParams const& WCParams);
	
private:
	void SetupOverlayWidgetController(FWidgetControllerParams const& WCParams);
	
	/* WIDGETS */
	UPROPERTY()
	TObjectPtr<UCRUserWidget> OverlayWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> OverlayWidgetClass;
	
	/* WIDGETS CONTROLLERS */
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
