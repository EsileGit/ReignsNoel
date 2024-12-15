// Fill out your copyright notice in the Description page of Project Settings.


#include "CRAttributeSet.h"
//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::ClampAttributeOnChange(FGameplayAttribute const& attribute, float& newValue) const
{
}
