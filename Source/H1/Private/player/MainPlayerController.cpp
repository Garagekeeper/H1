


#include "player/MainPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"

AMainPlayerController::AMainPlayerController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (auto* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		SubSystem->AddMappingContext(InputMappingContext, GameInputPriority);
	}
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (auto* InputCmp = Cast<UEnhancedInputComponent>(InputComponent))
	{
		InputCmp->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMainPlayerController::Input_Move);
		InputCmp->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AMainPlayerController::Input_Look);
	}
}

void AMainPlayerController::Input_Move(const FInputActionValue& InputValue)
{
	FVector2D MoveInput = InputValue.Get<FVector2D>();
	
	// 카메라 회전을 기준으로 앞뒤 결정
	if (MoveInput.X != 0)
	{
		FRotator Rotatr = GetControlRotation();
		FVector Dir = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotatr.Yaw, 0));
		GetPawn()->AddMovementInput(Dir, MoveInput.X);
	}

	// 카메라 회전을 기준으로 좌우 결정
	if (MoveInput.Y != 0)
	{
		FRotator Rotatr = GetControlRotation();
		FVector Dir = UKismetMathLibrary::GetRightVector(FRotator(0, Rotatr.Yaw, 0));
		GetPawn()->AddMovementInput(Dir, MoveInput.Y);
	}
}

void AMainPlayerController::Input_Look(const FInputActionValue& InputValue)
{
	float YawVal = InputValue.Get<float>();
	AddYawInput(YawVal);
}
