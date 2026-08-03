#pragma once

#include "CoreMinimal.h"
#include "player/BaseCharacter.h"
#include "MainChahracter.generated.h"

class UCameraComponent;
class UInputAction;
class USkeletalMeshComponent;
class USpringArmComponent;

struct FInputActionValue;

UCLASS()
class H1_API AMainChahracter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainChahracter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


#pragma region Input Binded Func
	void OnMove(const FInputActionValue& Value);
#pragma endregion


protected:

#pragma region Input Variable
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> IA_Move;
#pragma endregion


#pragma region Component Variable
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USpringArmComponent> CameraSpringArmComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UCameraComponent> CameraComponent = nullptr;


	/*-----------------------------
	|	  Moduled Skeletal Mesh
	------------------------------*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> Head;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> Torso;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> Arms;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> LowerLeg;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> UpperLeg;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> Boots;
#pragma endregion


};
