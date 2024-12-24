// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeInfo.h"

#include "GameFramework/GameSession.h"

FCRAttributeInfo UAttributeInfo::FindAttributeInfoForTag(FGameplayTag const& attributeTag, bool bLogNotFound) const
{
	for (FCRAttributeInfo const& info : AttributeInfos)
	{
		if (info.AttributeTag.MatchesTagExact(attributeTag))
		{
			return info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogGameSession, Error, TEXT("Can't find info for attribute tag [%s] on Attribute info [%s]"),
			*attributeTag.ToString(), *GetNameSafe(this));
	}
	return FCRAttributeInfo();
}

