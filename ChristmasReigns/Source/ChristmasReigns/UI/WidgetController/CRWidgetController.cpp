// Fill out your copyright notice in the Description page of Project Settings.


#include "CRWidgetController.h"

#include "ChristmasReigns/GameplayAbilitySystem/AttributeSet/CRAttributeSet.h"


//----------------------------------------------------------------------------------------------------------------------
void UCRWidgetController::SetWidgetControllerParams(FWidgetControllerParams const& WCParams)
{
	PlayerController		= WCParams.PlayerController;
	PlayerState				= WCParams.PlayerState;
	AbilitySystemComponent	= WCParams.AbilitySystemComponent;
	AttributeSet			= WCParams.AttributeSet;
}

//----------------------------------------------------------------------------------------------------------------------
UCRAttributeSet* UCRWidgetController::ModifyCRAttributeSet()
{
	if (!CRAttributeSet)
	{
		CRAttributeSet = Cast<UCRAttributeSet>(AttributeSet);
	}
	return CRAttributeSet;
}
