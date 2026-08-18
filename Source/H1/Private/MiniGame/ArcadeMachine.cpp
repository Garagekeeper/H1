


#include "MiniGame/ArcadeMachine.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "player/MainPlayerController.h"
#include "Component/StratagemHeroComponent.h"
#include "Components/WidgetComponent.h"
#include "Widget/StaratagemHeroWidget.h"
#include "Interface/MiniGameInterface.h"

// Sets default values
AArcadeMachine::AArcadeMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ArcadeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(ArcadeMesh);

	WidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComp->SetupAttachment(RootComponent);

	MiniGameComponent = CreateDefaultSubobject<UMiniGameActorComponent>(TEXT("MiniGame2"));

	AutoPossessAI = EAutoPossessAI::Disabled;
	AutoPossessPlayer = EAutoReceiveInput::Disabled;
}

// Called when the game starts or when spawned
void AArcadeMachine::BeginPlay()
{
	Super::BeginPlay();


	if (UMiniGameActorComponent* ActiveiniGame = MiniGameComponent)
	{
		ActiveiniGame->OnSendUICommand.AddDynamic(this, &AArcadeMachine::RelayUICommand);
	}
}

// Called every frame
void AArcadeMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArcadeMachine::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, TEXT("Interact call"));
}

void AArcadeMachine::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	

	// TODO 바인딩 위치 바꾸기
	// 여기서 하면 안좋뎅
	APlayerController* PC = Cast<APlayerController>(NewController);
	if (PC && MiniGameInputMappingContext)
	{
		if (auto* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			SubSystem->AddMappingContext(MiniGameInputMappingContext, GameInputPriority);
		}
	}

	//TODO StartGame..?
	MiniGameComponent->GameStart();
}

void AArcadeMachine::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		InputComp->BindAction(IA_Arrow_Up, ETriggerEvent::Started, this, &AArcadeMachine::Input_Arrow_Up);
		InputComp->BindAction(IA_Arrow_Down, ETriggerEvent::Started, this, &AArcadeMachine::Input_Arrow_Down);
		InputComp->BindAction(IA_Arrow_Left, ETriggerEvent::Started, this, &AArcadeMachine::Input_Arrow_Left);
		InputComp->BindAction(IA_Arrow_Right, ETriggerEvent::Started, this, &AArcadeMachine::Input_Arrow_Right);
		InputComp->BindAction(IA_Exit, ETriggerEvent::Started, this, &AArcadeMachine::Input_Exit);
	}
}

void AArcadeMachine::RelayUICommand(const FMinigameUICommand& Command)
{
	if (!WidgetComp) return;
	UUserWidget* UserWidget = WidgetComp->GetUserWidgetObject();
	if (UserWidget->Implements<UMiniGameInterface>())
	{
		IMiniGameInterface::Execute_ExecuteUICommand(UserWidget, Command);
	}
}

void AArcadeMachine::Input_Arrow_Up(const FInputActionValue& InputValue)
{
	if (InputValue.Get<bool>())
	{
		if (!MiniGameComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("MiniGameComponent was nullptr"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Up Arraow Started"));
			MiniGameComponent->CheckInput(EDirType::Up);
		}

	}

}

void AArcadeMachine::Input_Arrow_Down(const FInputActionValue & InputValue)
{
	if (InputValue.Get<bool>())
	{
		if (!MiniGameComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("MiniGameComponent was nullptr"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Down Arraow Started"));
			MiniGameComponent->CheckInput(EDirType::Down);
		}
	}
}

void AArcadeMachine::Input_Arrow_Right(const FInputActionValue & InputValue)
{
	if (InputValue.Get<bool>())
	{
		if (!MiniGameComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("MiniGameComponent was nullptr"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Right Arraow Started"));
			MiniGameComponent->CheckInput(EDirType::Right);
		}

	}
}

void AArcadeMachine::Input_Arrow_Left(const FInputActionValue & InputValue)
{
	if (InputValue.Get<bool>())
	{
		if (!MiniGameComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("MiniGameComponent was nullptr"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Left Arraow Started"));
			MiniGameComponent->CheckInput(EDirType::Left);
		}

	}
}

void AArcadeMachine::Input_Exit(const FInputActionValue& InputValue)
{
	if (AMainPlayerController* MPC = Cast<AMainPlayerController>(GetController()))
	{
		MPC->PossessToPrev();
	}
}


