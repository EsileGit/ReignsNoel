// Fill out your copyright notice in the Description page of Project Settings.


#include "CRAbilitySystemLibrary.h"

#include "ChristmasReigns/GameplayAbilitySystem/AttributeSet/CRAttributeSet.h"
#include "ChristmasReigns/Player/CRPlayerState.h"
#include "ChristmasReigns/UI/CRHud.h"
#include "ChristmasReigns/UI/WidgetController/CRWidgetController.h"

#include "Kismet/GameplayStatics.h"

namespace 
{
	// ---------------------------------------------------------------------------------------------------------------------
	FWidgetControllerParams GetLocalWidgetControllerParams(UObject const* worldContextObject)
	{
		APlayerController * PC = UGameplayStatics::GetPlayerController(worldContextObject, 0);
		if (!IsValid(PC))
		{
			return FWidgetControllerParams();
		}
		ACRPlayerState* PS = PC->GetPlayerState<ACRPlayerState>();
		UAbilitySystemComponent * ASC = PS->GetAbilitySystemComponent();
		UAttributeSet * AS = PS->ModifyAttributeSet();
		return FWidgetControllerParams(PC, PS, ASC, AS);	
	}
}

//----------------------------------------------------------------------------------------------------------------------
UOverlayWidgetController* UCRAbilitySystemLibrary::GetOverlayWidgetController(UObject const* worldContextObject)
{
	if (APlayerController const* PC = UGameplayStatics::GetPlayerController(worldContextObject, 0))
	{
		if(ACRHud* CRHud = Cast<ACRHud>(PC->GetHUD()))
		{
			return CRHud->GetOrCreateOverlayWidgetController(GetLocalWidgetControllerParams(worldContextObject));
		}
	}
	return nullptr;
}
