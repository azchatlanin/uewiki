#include "RotateAroundVector_CPP.h"

ARotateAroundVector_CPP::ARotateAroundVector_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
	AngleAxis = 0;
}

void ARotateAroundVector_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void ARotateAroundVector_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = FVector (0.f, 0.f, 800.f);
	FVector Radius = FVector(400.f, 0.f, 0.f);
	AngleAxis++;
	if(AngleAxis >= 360.0f) AngleAxis = 0.f;
	FVector RotateValue = Radius.RotateAngleAxis(AngleAxis, FVector (0.f, 0.f, 1.f));

	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z += RotateValue.Z;
	
	SetActorLocation(NewLocation);
}

