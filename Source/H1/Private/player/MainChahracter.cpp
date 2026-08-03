// Fill out your copyright notice in the Description page of Project Settings.


#include "player/MainChahracter.h"

// Sets default values
AMainChahracter::AMainChahracter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

