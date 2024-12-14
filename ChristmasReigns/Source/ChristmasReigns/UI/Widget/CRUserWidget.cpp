// Fill out your copyright notice in the Description page of Project Settings.


#include "CRUserWidget.h"

FGaugeData UCRUserWidget::GetGaugeData()
{
	FGaugeData data;
	data.Percent = .50f;
	data.bIsVisible = false;
	
	return data;
}
