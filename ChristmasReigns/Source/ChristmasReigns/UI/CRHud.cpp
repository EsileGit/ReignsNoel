// Fill out your copyright notice in the Description page of Project Settings.


#include "CRHud.h"

#include "Blueprint/UserWidget.h"
#include "Widget/CRUserWidget.h"

void ACRHud::InitOverlay()
{
	UUserWidget* pWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UCRUserWidget>(pWidget);
	
	pWidget->AddToViewport();
}
