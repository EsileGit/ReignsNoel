// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayWidgetController.h"

#include "ChristmasReigns/GameplayAbilitySystem/AttributeSet/CRAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues() const
{
	Super::BroadcastInitialValues();
	
	if (UCRAttributeSet const* pAttributeSet =  Cast<UCRAttributeSet>(AttributeSet))
	{
		OnMentalChanged.Broadcast(pAttributeSet->GetMental());
		OnMaxMentalChanged.Broadcast(pAttributeSet->GetMaxMental());
	}
}
