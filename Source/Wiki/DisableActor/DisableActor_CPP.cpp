#include "DisableActor_CPP.h"

ADisableActor_CPP::ADisableActor_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADisableActor_CPP::BeginPlay()
{
	Super::BeginPlay();	

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
}

void ADisableActor_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

