
#include "CRGameplayTags.h"

#include "GameplayTagsManager.h"

FCRGameplayTags FCRGameplayTags::GameplayTags;

namespace
{
	void CreateAndAssignGameplayTag(FGameplayTag& outTag, FName const& tagName, FString const& comment)
	{
		outTag = UGameplayTagsManager::Get().AddNativeGameplayTag(tagName, comment);
	}
}

void FCRGameplayTags::InitializeNativeGameplayTags()
{
	CreateAndAssignGameplayTag(GameplayTags.Attributes_Mental, "Attributes.Mental", "Amount of mental health from main player");
	CreateAndAssignGameplayTag(GameplayTags.Attributes_MotherPride, "Attributes.MotherPride", "How much mother is proud of us");
	CreateAndAssignGameplayTag(GameplayTags.Attributes_Popularity, "Attributes.Popularity", "How popular is Christmas");
}








