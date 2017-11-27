// Fill out your copyright notice in the Description page of Project Settings.

#include "Interaction.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "FileHelper.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/TimerManager.h"


// Sets default values
AInteraction::AInteraction()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TestSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	TestSprite->OnInputTouchBegin.AddDynamic(this, &AInteraction::OnTouchBegin);
	RootComponent = TestSprite;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 2048.0f;
	Camera->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	TextAdress = "C:/Users/Marcelo/Documents/Unreal Projects/FisiQuiz/PerguntasERespostas.txt";
	ReadText();
}


// Called when the game starts or when spawned
void AInteraction::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(AnswerTime, this,
		&AInteraction::Tempo, 90.0f, false);

	
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
//Como fazer para verificar se o endereço do  arquivo é válido???

void AInteraction::ReadText()
//Metodo lê mas não separa o texto, como fazer??
{
	FString TextToRead;
	FFileHelper::LoadFileToString(TextToRead, *TextAdress);
	TArray<FString> Lines;
	int32 lineCount = TextToRead.ParseIntoArray(Lines, _T("\n"), true);
    FString Write =	ConvertText(Lines);

	//UE_LOG(LogTemp, Warning,TEXT("MyText: %s"),*Write);

	Write.ParseIntoArray(MainArray, TEXT("%"), true);

	int jorge = FMath::RandRange(0, MainArray.Num() - 1);

	TArray<FString> PerguntaAtual;
	TArray<FString> Respostas;
	for (int i = 1; i < PerguntaAtual.Num(); i++) {
		Respostas.Add(PerguntaAtual[i]);
	}


	MainArray[jorge].ParseIntoArray(PerguntaAtual, TEXT("@"), true);

	for (int i = 0; i < PerguntaAtual.Num(); i++)
	{
		if (i == 0) {
			UE_LOG(LogTemp, Warning, TEXT("PERGUNTA %d:  %s"), jorge, *PerguntaAtual[i]);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("RESPOSTA %d: %s"),i, *PerguntaAtual[i]);
		}
		
	}
	/*UE_LOG(LogTemp, Warning, TEXT("%d perguntas"), MainArray.Num());
	UE_LOG(LogTemp, Warning, TEXT("%da Pergunta: %s"),jorge, *MainArray[jorge]);*/
}

void AInteraction::Tempo()
{
	UE_LOG(LogTemp, Warning, TEXT("TimeIsOver"));
}

FString AInteraction::ConvertText(TArray<FString> Lines)
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

