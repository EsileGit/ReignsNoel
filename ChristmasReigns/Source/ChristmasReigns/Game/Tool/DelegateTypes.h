
#pragma once

#include "CoreMinimal.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeModifiedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIntValueModifiedSignature, int32, NewValue);