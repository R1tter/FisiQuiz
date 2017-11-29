// Fill out your copyright notice in the Description page of Project Settings.

#include "Manager.h"
#include "FileHelper.h"
#include "Runtime/Engine/Public/GeneratedCodeHelpers.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/TimerManager.h"


// Sets default values
AManager::AManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TextAdress = "C:/Users/Marcelo/Documents/Unreal Projects/FisiQuiz/PerguntasERespostas.txt";

	ReadText();
	FCustomThunkTemplates::Array_Shuffle(MainArray);


}

// Called when the game starts or when spawned
void AManager::BeginPlay()
{
	Super::BeginPlay();
	ResetAndPick();
	NaHora = 0;
	TotalSec = 30;

	GetWorldTimerManager().SetTimer(AnswerTime, this,
		&AManager::Tempo, 1.0f, true);
	
}

// Called every frame
void AManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FString> AManager::ShuffleAnswers(TArray<FString> MyRespostas)
{
	FCustomThunkTemplates::Array_Shuffle(MyRespostas);
	return MyRespostas;
}

void AManager::ReadText()
//Metodo lê mas não separa o texto, como fazer??
{
	FString TextToRead;
	FFileHelper::LoadFileToString(TextToRead, *TextAdress);
	TArray<FString> Lines;
	int32 lineCount = TextToRead.ParseIntoArray(Lines, _T("\n"), true);
	FString Write = ConvertText(Lines);

	//UE_LOG(LogTemp, Warning,TEXT("MyText: %s"),*Write);

	Write.ParseIntoArray(MainArray, TEXT("%"), true);

}

FString AManager::ConvertText(TArray<FString> Lines)
{
	FString FinalText = FString("");
	for (int i = 0; i < Lines.Num(); i++) {
		//Append text
		FinalText.Append(Lines[i]);
		if (i < Lines.Num() - 1) {
			//Append \n
			FinalText.Append("\n");
		}
	}
	return FinalText;
}

void AManager::Tempo()
{
	Segundos--;
	UE_LOG(LogTemp, Warning, TEXT("%d"), Segundos);
	if (Segundos <= 0) {
		ResetAndPick();
	}
}

void AManager::ResetAndPick()
{

	Segundos = TotalSec;



	NaHora++;
	if (NaHora >= MainArray.Num()) {
		NaHora = 0;
	}
	UE_LOG(LogTemp, Warning, TEXT("%d"), NaHora);

	QnA.Reset();
	Respostas.Reset();
	MainArray[NaHora].ParseIntoArray(QnA, TEXT("@"), true);

	for (int i = 1; i < QnA.Num(); i++) {
		Respostas.Add(QnA[i]);
	}

	Respostas = ShuffleAnswers(Respostas);

}

void AManager::AddPoints()
{
	Acertos++;
	UE_LOG(LogTemp, Warning, TEXT("ACERTOU!!"));
}

bool AManager::PauseGeral()
{

	if (NaHora % 10 == 0) {
		GetWorldTimerManager().PauseTimer(AnswerTime);
		return true;
	}
	return false;
}

void AManager::UnPauseGeral()
{
	GetWorldTimerManager().UnPauseTimer(AnswerTime);
}

float AManager::GetSegundos()
{

	float MyPercent = Segundos / TotalSec;
	return MyPercent;
}

int AManager::GetAcertos()
{
	return Acertos;
}

int AManager::GetNaHora()
{
	return NaHora;
}
