#include "RotateActorAroundPlayer_CPP.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ARotateActorAroundPlayer_CPP::ARotateActorAroundPlayer_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	Dimensions = FVector (300, 0, 0);
	AxisVector = FVector (0, 0, 1);
	Multiplier = 50.f;
}

void ARotateActorAroundPlayer_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void ARotateActorAroundPlayer_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorLocation();
	
	AngleAxis += DeltaTime * Multiplier;

	if(AngleAxis >= 360.0f) 
	{
		AngleAxis = 0;
	}

	FVector RotateValue = Dimensions.RotateAngleAxis(AngleAxis, AxisVector);

	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z += RotateValue.Z;

	FRotator NewRotation = FRotator(0, AngleAxis, 0);
	
	FQuat QuatRotation = FQuat(NewRotation);

	SetActorLocationAndRotation(NewLocation, QuatRotation, false, 0, ETeleportType::None);
}

