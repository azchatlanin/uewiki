#define printInt(data) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Orange, FString::Printf(TEXT("Number Of Pawns: %d"), data));

#include "GetNumberOfPawns_CPP.h"

AGetNumberOfPawns_CPP::AGetNumberOfPawns_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGetNumberOfPawns_CPP::BeginPlay()
{
	Super::BeginPlay();	

	int32 NumberPawns = GetWorld()->GetNumPawns();
	printInt(NumberPawns);
}

void AGetNumberOfPawns_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

