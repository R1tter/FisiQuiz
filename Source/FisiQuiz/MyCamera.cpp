// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCamera.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AMyCamera::AMyCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMyCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

