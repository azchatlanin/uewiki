#include "RotatingAngleAxis_CPP.h"


ARotatingAngleAxis_CPP::ARotatingAngleAxis_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	Dimensions = FVector (300, 0, 0);
	AxisVector = FVector (0, 0, 1);
	Multiplier = 50.f;
}

void ARotatingAngleAxis_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void ARotatingAngleAxis_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = FVector (0.f, 0.f, 800.f);

	AngleAxis += DeltaTime * Multiplier;

	if(AngleAxis >= 360.f) AngleAxis = 0.f;
	
	FVector RotateValue = Dimensions.RotateAngleAxis(AngleAxis, AxisVector);

	// if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("RotateValue: %s"), *RotateValue.ToString()));	
	// if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("AngleAxis: %f"), AngleAxis));

	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z += RotateValue.Z;

	SetActorLocation(NewLocation, false, 0, ETeleportType::None);
}

