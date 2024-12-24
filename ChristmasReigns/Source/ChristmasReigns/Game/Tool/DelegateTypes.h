
#pragma once

#include "CoreMinimal.h"
#include "DelegateTypes.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeModifiedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIntValueModifiedSignature, int32, NewValue);
// Do no touch any of the following code, something makes it magically works, I don't know what
/**
 * toto

UCLASS()
class MEMENTOMORI_API UAttributeDelegateTypes: public UObject
{
	GENERATED_BODY()
public:
	UAttributeDelegateTypes(){}
}; */