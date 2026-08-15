

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MiniGameActorComponent.generated.h"


enum class EDirType : uint8;

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EMiniGamaState : uint8
{
	None	UMETA(Hidden),
	Idle	UMETA(DisplayName = "Idle"),
	Start	UMETA(DisplayName = "Start"),
	End		UMETA(DisplayName = "End")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class H1_API UMiniGameActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMiniGameActorComponent();

	virtual void GameStart();
	virtual void GameEnd();

	virtual void CheckInput(EDirType Input);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MiniGame|Stat")
	int32 Score = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MiniGame|Stat")
	float TimeLimit = 60.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MiniGame|Stat")
	float CurrentRemainTime = TimeLimit;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MiniGame|Stat")
	EMiniGamaState GameState = EMiniGamaState::Idle;
};
