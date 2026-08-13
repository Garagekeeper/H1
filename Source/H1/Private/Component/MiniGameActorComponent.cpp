


#include "Component/MiniGameActorComponent.h"

// Sets default values for this component's properties
UMiniGameActorComponent::UMiniGameActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMiniGameActorComponent::GameStart()
{
	GameState = EMiniGamaState::Start;
}

void UMiniGameActorComponent::GameEnd()
{
	GameState = EMiniGamaState::End;
}


// Called when the game starts
void UMiniGameActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMiniGameActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	//TODO 테스트가 끝나면 켜기
	/*if (GameState == EMiniGamaState::Start)
	{
		CurrentRemainTime -= DeltaTime;
		if (CurrentRemainTime <= 0.0f)
		{
			GameEnd();
		}
	}*/

}

void UMiniGameActorComponent::CheckInput(EDirType Input)
{

}

