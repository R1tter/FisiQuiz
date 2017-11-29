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

	FString TextAdress;

	TArray<FString> MainArray;

	FTimerHandle AnswerTime;

	int NaHora;

	int Acertos;



	float Segundos;
	
	float TotalSec;




	TArray<FString> ShuffleAnswers(TArray<FString> MyRespostas);

	FString ConvertText(TArray<FString> Lines);

	void Tempo();

	void ReadText();


public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Question")
	TArray<FString> QnA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Question")
	TArray<FString> Respostas;

	UFUNCTION(BlueprintCallable, Category = "Shoot")
		void ResetAndPick();

	UFUNCTION(BlueprintCallable, Category = "Shoot")
		void AddPoints();

	UFUNCTION(BlueprintCallable, Category = "Shoot")
		bool PauseGeral();

	UFUNCTION(BlueprintCallable, Category = "Shoot")
		void UnPauseGeral();

	UFUNCTION(BlueprintCallable, Category = "Shoot")
		float GetSegundos();

	UFUNCTION(BlueprintCallable, Category = "Shoot")
		int GetAcertos();

	UFUNCTION(BlueprintCallable, Category = "Shoot")
		int GetNaHora();


};
