#include "LineTraceOnTick_CPP.h"
#include "DrawDebugHelpers.h"

ALineTraceOnTick_CPP::ALineTraceOnTick_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	Cube = CreateDefaultSubobject<class UStaticMeshComponent>(TEXT("Visual Representation"));
	RootComponent = Cube;

	bDown = false;
}

void ALineTraceOnTick_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void ALineTraceOnTick_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult OutHit;
	FVector CurrentLocation = GetActorLocation();
	FVector ForwardVector = GetActorUpVector();
	FVector End = ((ForwardVector * -100.f) + CurrentLocation);
	
	FCollisionQueryParams CollisionParams;
	CollisionParams.bTraceComplex = true;
	CollisionParams.AddIgnoredActor(this);

	DrawDebugLine(GetWorld(), CurrentLocation, End, FColor::Green, false, 0.5f, 0, 1.f);

	if(GetWorld()->LineTraceSingleByChannel(OutHit, CurrentLocation, End, ECC_Visibility, CollisionParams)) 
	{
		if(OutHit.bBlockingHit)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You are hitting: %s"), *OutHit.GetActor()->GetName()));
		}
	}

	
	if (CurrentLocation.Z > 400.f) 
	{		
		bDown = true;
	}
	if (CurrentLocation.Z < -10.f) 
	{
		bDown = false;
	}

	if (bDown) 
	{
		CurrentLocation.Z -= 1.f;
	} 
	else
	{
		CurrentLocation.Z += 1.f;
	}

	SetActorLocation(CurrentLocation);
}

