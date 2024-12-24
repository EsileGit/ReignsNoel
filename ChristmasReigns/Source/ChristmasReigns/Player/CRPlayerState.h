// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"

#include "ChristmasReigns/GameplayAbilitySystem/CRAbilitySystemComponent.h"

#include "GameFramework/PlayerState.h"
#include "CRPlayerState.generated.h"

class UCRAttributeSet;
class UCRAbilitySystemComponent;

/**
 * Holds attributes defining the player state
 */
UCLASS()
class CHRISTMASREIGNS_API ACRPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	ACRPlayerState();
	UCRAttributeSet* ModifyAttributeSet() {return AttributeSet;}
	
	/** Implement IAbilitySystemInterface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override {return AbilitySystemComponent;}
	/** END Implement IAbilitySystemInterface */
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCRAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	TSubclassOf<UGameplayEffect> DefaultAttributes;
	
	UPROPERTY()
	TObjectPtr<UCRAttributeSet> AttributeSet;

private:
	void InitializeAttributes() const;
	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> const& gameplayEffectClass, float level) const;
	void InitializeASC();
	void InitializeHUD();
};
