#pragma once
#include "GameplayTagContainer.h"




/**
 * GameplayTags
 *
 * Singleton containing native gameplay tags
 */
struct FCRGameplayTags
{
public:
  static FCRGameplayTags const& Get() {return GameplayTags;}
  static void InitializeNativeGameplayTags();
    
  FGameplayTag Attributes_Mental;
  FGameplayTag Attributes_Popularity;
  FGameplayTag Attributes_MotherPride;
	
private:
 static FCRGameplayTags GameplayTags;
};