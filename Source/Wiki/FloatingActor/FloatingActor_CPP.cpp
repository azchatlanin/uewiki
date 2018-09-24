#include "FloatingActor_CPP.h"

AFloatingActor_CPP::AFloatingActor_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFloatingActor_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void AFloatingActor_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// on every frame change location for a smooth floating actor
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.X += DeltaHeight * XValue;
	NewLocation.Y += DeltaHeight * YValue;
	NewLocation.Z += DeltaHeight * ZValue;

	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

