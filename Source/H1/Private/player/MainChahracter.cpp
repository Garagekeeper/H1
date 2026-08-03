#include "player/MainChahracter.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "InputactionValue.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AMainChahracter::AMainChahracter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraSpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	CameraComponent->SetupAttachment(CameraSpringArmComponent);

	USkeletalMeshComponent* MainSkeletalMesh = GetMesh();

	Head = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HEAD"));
	Head->SetupAttachment(MainSkeletalMesh);
	Head->SetLeaderPoseComponent(MainSkeletalMesh, false, false);

	Torso = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Torso"));
	Torso->SetupAttachment(MainSkeletalMesh);
	Torso->SetLeaderPoseComponent(MainSkeletalMesh, false, false);

	Boots = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Boots"));
	Boots->SetupAttachment(MainSkeletalMesh);
	Boots->SetLeaderPoseComponent(MainSkeletalMesh, false, false);

	LowerLeg = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LowerLeg"));
	LowerLeg->SetupAttachment(MainSkeletalMesh);
	LowerLeg->SetLeaderPoseComponent(MainSkeletalMesh, false, false);

	UpperLeg = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("UpperLeg"));
	UpperLeg->SetupAttachment(MainSkeletalMesh);
	UpperLeg->SetLeaderPoseComponent(MainSkeletalMesh, false, false);

	Arms = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Arms"));
	Arms->SetupAttachment(MainSkeletalMesh);
	Arms->SetLeaderPoseComponent(MainSkeletalMesh, false, false);
}

// Called when the game starts or when spawned
void AMainChahracter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainChahracter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainChahracter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// 이동 관련 키 매핑
		EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered,this, &AMainChahracter::OnMove);
	}

}

void AMainChahracter::OnMove(const FInputActionValue& Value)
{}



