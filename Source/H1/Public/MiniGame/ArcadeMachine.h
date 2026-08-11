

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interface/InteractiveActor.h"
#include "ArcadeMachine.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;

UCLASS()
class H1_API AArcadeMachine : public APawn, public IInteractiveActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArcadeMachine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	///UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	virtual void Interact_Implementation() override;
	// 폰이 빙의되었을 때 호출되는 함수 오버라이드
	virtual void PossessedBy(AController* NewController) override;

	// 폰이 빙의될 때 언리얼이 자동으로 호출해주는 입력 설정 함수
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Input_Arrow_Up(const FInputActionValue& InputValue);
	void Input_Arrow_Down(const FInputActionValue& InputValue);
	void Input_Arrow_Right(const FInputActionValue& InputValue);
	void Input_Arrow_Left(const FInputActionValue& InputValue);
	void Input_Exit(const FInputActionValue& InputValue);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> ArcadeMesh;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> MiniGameInputMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> IA_Arrow_Up;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> IA_Arrow_Down;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> IA_Arrow_Left;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> IA_Arrow_Right;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<class UInputAction> IA_Exit;


	UPROPERTY(EditAnywhere, Category = Input)
	int32 GameInputPriority = 0;


};
