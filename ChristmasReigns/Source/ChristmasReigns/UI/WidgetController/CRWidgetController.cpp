// Fill out your copyright notice in the Description page of Project Settings.


#include "CRWidgetController.h"


void UCRWidgetController::SetWidgetControllerParams(FWidgetControllerParams const& WCParams)
{
	PlayerController		= WCParams.PlayerController;
	PlayerState				= WCParams.PlayerState;
	AbilitySystemComponent	= WCParams.AbilitySystemComponent;
	AttributeSet			= WCParams.AttributeSet;
}
