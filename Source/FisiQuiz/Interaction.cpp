// Fill out your copyright notice in the Description page of Project Settings.

#include "Interaction.h"
#include "PaperSpriteComponent.h"


// Sets default values
AInteraction::AInteraction()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TestSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	TestSprite->OnInputTouchBegin.AddDynamic(this, &AInteraction::OnTouchBegin);
	RootComponent = TestSprite;

}

// Called when the game starts or when spawned
void AInteraction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteraction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInteraction::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AInteraction::OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent * TouchedComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("Touch"));
}

