#define printT(data) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Blue, data);
#define printV(data) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Orange, FString::Printf(TEXT("Vector: %s"), data));
#define printI(data) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Orange, FString::Printf(TEXT("Number: %d"), data));
#define printF(data) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Orange, FString::Printf(TEXT("Float: %f"), data));
#define printB(data) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Orange, FString::Printf(TEXT("Bool: %s"), (data ? TEXT("True") : TEXT("False")))); 

#include "DebugLogger_CPP.h"

// Логирование в с++

DEFINE_LOG_CATEGORY_STATIC(DebugLogger_CPP, Warning, All);

ADebugLogger_CPP::ADebugLogger_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADebugLogger_CPP::BeginPlay()
{
	Super::BeginPlay();

	// 1
	UE_LOG(DebugLogger_CPP, Warning, TEXT("Starter running"));

	// 2
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Blue, TEXT("SCREEN MESSAGE"));

	// 3
	printT("Hello World!");

	// 4
	FVector Vec = FVector(1.f, 1.f, 1.f);
	printV(*Vec.ToString());

	// 5
	printI(123);

	// 6
	printB(true);

	// 7
	printF(4.f)
}

void ADebugLogger_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

