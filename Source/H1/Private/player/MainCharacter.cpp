#include "player/MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "InputactionValue.h"
#include "Components/SkeletalMeshComponent.h"
#include "Player/MainCharacterAnimInstance.h"
#include "Components/SphereComponent.h"
#include "Interface/InteractiveActor.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set Moduled Mesh
	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraSpringArmComponent->SetupAttachment(RootComponent);
	CameraSpringArmComponent->SetRelativeRotation(FRotator(-30, 0, 0));
	CameraSpringArmComponent->TargetArmLength = 700.0f;
	CameraSpringArmComponent->bUsePawnControlRotation = true;
	CameraSpringArmComponent->bInheritPitch = false;
	CameraSpringArmComponent->bInheritRoll = false;
	CameraSpringArmComponent->bInheritYaw = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	CameraComponent->SetupAttachment(CameraSpringArmComponent);

	USkeletalMeshComponent* MainSkeletalMesh = GetMesh();
	MainSkeletalMesh->SetRelativeLocationAndRotation(FVector(0, 0, -88.0f), FRotator(0, -90, 0));

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


	// SetSphere Colliosion
	InteractDetecSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractDetecSphere"));
	InteractDetecSphere->SetupAttachment(RootComponent);
	InteractDetecSphere->SetSphereRadius(500.0f);

	// 플레이어가 움직이는 방향으로 회전
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 1200.0f;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();


	// 모듈 skeletalMesh라고 표시
	// 이 값이 ABP에 영향을 줌
	if (UMainCharacterAnimInstance* AnimInstance = Cast<UMainCharacterAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		AnimInstance->SetModuledMeshBool(true);
	}

	if (InteractDetecSphere)
	{
		InteractDetecSphere->OnComponentBeginOverlap.AddDynamic(this, &AMainCharacter::OnSphereBeginOverlap);
		InteractDetecSphere->OnComponentEndOverlap.AddDynamic(this, &AMainCharacter::OnSphereEmdOverlap);
	}

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainCharacter::UnPossessed()
{
	Super::UnPossessed();
	GetCharacterMovement()->StopMovementImmediately();
	GetCharacterMovement()->DisableMovement();

}

void AMainCharacter::PossessedBy(AController* NewController)
{
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	GetCharacterMovement()->StopMovementImmediately();
}

void AMainCharacter::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->Implements<UInteractiveActor>())
	{
		OverlappedInteractableActor.Add(OtherActor);
	}
}

void AMainCharacter::OnSphereEmdOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->Implements<UInteractiveActor>())
	{
		OverlappedInteractableActor.Remove(OtherActor);
	}
}



