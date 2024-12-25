// Fill out your copyright notice in the Description page of Project Settings.


#include "CRAssetManager.h"

#include "ChristmasReigns/GameplayAbilitySystem/Library/CRGameplayTags.h"

UCRAssetManager& UCRAssetManager::Get()
{
	check(GEngine);

	UCRAssetManager* CRAssetManager = Cast<UCRAssetManager>(GEngine->AssetManager);

	return *CRAssetManager;
}

void UCRAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FCRGameplayTags::InitializeNativeGameplayTags();
}
