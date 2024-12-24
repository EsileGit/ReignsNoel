// Fill out your copyright notice in the Description page of Project Settings.


#include "CRHud.h"

#include "Blueprint/UserWidget.h"
#include "Widget/CRUserWidget.h"

#include "WidgetController/OverlayWidgetController.h"

//----------------------------------------------------------------------------------------------------------------------
void ACRHud::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	UUserWidget* pWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UCRUserWidget>(pWidget);
	
	const FWidgetControllerParams widgetControllerParams(PC, PS, ASC, AS);
	// Create the widget controller
	GetOrCreateOverlayWidgetController(widgetControllerParams);
	OverlayWidget->SetWidgetController(OverlayWidgetController);
	OverlayWidgetController->BroadcastInitialValues();
	
	pWidget->AddToViewport();
}

//----------------------------------------------------------------------------------------------------------------------
UOverlayWidgetController* ACRHud::GetOrCreateOverlayWidgetController(FWidgetControllerParams const& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		SetupOverlayWidgetController(WCParams);
	}
	return OverlayWidgetController;
}

//----------------------------------------------------------------------------------------------------------------------
void ACRHud::SetupOverlayWidgetController(FWidgetControllerParams const& WCParams)
{
	checkf(OverlayWidgetControllerClass, TEXT("No valid OverlayWidgetControllerClass in HUD, please fill it in"))
	OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
	OverlayWidgetController->SetWidgetControllerParams(WCParams);
	OverlayWidgetController->BindCallbacksToDependencies();
}
