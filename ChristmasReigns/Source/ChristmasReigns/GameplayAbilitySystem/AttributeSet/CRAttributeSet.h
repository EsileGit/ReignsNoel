// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CRAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * RPG Attributes relevant to the game
 */
UCLASS()
class CHRISTMASREIGNS_API UCRAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mental)
	FGameplayAttributeData Mental{50.f};
	ATTRIBUTE_ACCESSORS(UCRAttributeSet, Mental)
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMental)
	FGameplayAttributeData MaxMental {100.f};
	ATTRIBUTE_ACCESSORS(UCRAttributeSet, MaxMental)

protected:
	
	/**
	* These OnRep functions exist to make sure that the ability system internal representations are synchronized properly during replication
	**/
	UFUNCTION()
	virtual void OnRep_Mental(const FGameplayAttributeData& OldMental);
	UFUNCTION()
	virtual void OnRep_MaxMental(const FGameplayAttributeData& OldMaxMental);
	
private:
	void ClampAttributeOnChange(FGameplayAttribute const& attribute, float& newValue) const;
};
