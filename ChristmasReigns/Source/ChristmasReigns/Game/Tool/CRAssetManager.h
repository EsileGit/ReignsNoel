// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "CRAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class CHRISTMASREIGNS_API UCRAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static UCRAssetManager& Get();
protected:
	virtual void StartInitialLoading() override;
};
