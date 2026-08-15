

#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EDirType : uint8
{
	None,
	Up,
	Right,
	Down,
	Left
};

