// Fill out your copyright notice in the Description page of Project Settings.


#include "CRAttributeSet.h"

#include "Net/UnrealNetwork.h"

class UCRAttributeSet;

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	ClampAttributeOnChange(Attribute, NewValue);
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
	
	ClampAttributeOnChange(Attribute, NewValue);
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCRAttributeSet, Mental, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCRAttributeSet, Popularity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCRAttributeSet, MotherPride, COND_None, REPNOTIFY_Always);
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::OnRep_Mental(const FGameplayAttributeData& OldMental)
{
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::OnRep_MaxMental(const FGameplayAttributeData& OldMaxMental)
{
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::OnRep_Popularity(const FGameplayAttributeData& OldPopularity)
{
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::OnRep_MaxPopularity(const FGameplayAttributeData& OldMaxPopularity)
{
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::OnRep_MotherPride(const FGameplayAttributeData& OldMotherPride)
{
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::OnRep_MaxMotherPride(const FGameplayAttributeData& OldMaxMotherPride)
{
}

//----------------------------------------------------------------------------------------------------------------------
void UCRAttributeSet::ClampAttributeOnChange(FGameplayAttribute const& attribute, float& newValue) const
{
	if (attribute == GetMentalAttribute())
	{
		newValue = FMath::Clamp(newValue, 0.f, GetMaxMental());
	}
	if (attribute == GetPopularityAttribute())
	{
		newValue = FMath::Clamp(newValue, 0.f, GetMaxPopularity());
	}
	if (attribute == GetMotherPrideAttribute())
	{
		newValue = FMath::Clamp(newValue, 0.f, GetMaxMotherPride());
	}
}
