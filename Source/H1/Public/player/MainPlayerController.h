

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

struct FInputActionValue;
/**
 * 
 */
UCLASS()
class H1_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMainPlayerController(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void Input_Move(const FInputActionValue& InputValue);
	void Input_Look(const FInputActionValue& InputValue);

protected:
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> IA_Move;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> IA_Look;

	UPROPERTY(EditAnywhere, Category = Input)
	int32 GameInputPriority = 0;
};
