#include "WikiPawn_CPP.h"

AWikiPawn_CPP::AWikiPawn_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWikiPawn_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void AWikiPawn_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWikiPawn_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

