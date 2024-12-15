// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CRAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CHRISTMASREIGNS_API UCRAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UCRAbilitySystemComponent();
	void OnAbilityActorInfoSet();
	
protected:
	virtual void BeginPlay() override;

};
