// Fill out your copyright notice in the Description page of Project Settings.


#include "CRUserWidget.h"


//----------------------------------------------------------------------------------------------------------------------
void UCRUserWidget::SetWidgetController(UObject* inWidgetController)
{
	WidgetController = inWidgetController;
	OnWidgetControllerSet();
}

//----------------------------------------------------------------------------------------------------------------------
FGaugeData UCRUserWidget::GetGaugeData()
{
	FGaugeData data;
	data.Percent = .50f;
	data.bIsVisible = false;
	
	return data;
}
