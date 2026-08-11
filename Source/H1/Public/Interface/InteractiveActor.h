

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractiveActor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractiveActor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class H1_API IInteractiveActor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Interact();
};
