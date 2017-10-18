// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Manager.generated.h"

UCLASS()
class FISIQUIZ_API AManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	class Interaction* Resposta1;
	class Interaction* Resposta2;
	class Interaction* Resposta3;
	class Interaction* Resposta4;
	

	TArray<FString> QnA;

};
