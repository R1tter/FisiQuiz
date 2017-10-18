// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interaction.generated.h"

UCLASS()
class FISIQUIZ_API AInteraction : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AInteraction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	FString* GameText;

	UFUNCTION()
		void OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent* TouchedComponent);

	UPROPERTY(EditAnywhere)
		class UPaperSpriteComponent* TestSprite;
	
};
