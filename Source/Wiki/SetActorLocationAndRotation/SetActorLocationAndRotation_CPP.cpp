#include "SetActorLocationAndRotation_CPP.h"

ASetActorLocationAndRotation_CPP::ASetActorLocationAndRotation_CPP()
{
	NewLocation = FVector(0.f, 0.f, 100.f);
	NewRotation = FQuat(FRotator(300.f, 300.f, 300.f));
}

void ASetActorLocationAndRotation_CPP::BeginPlay()
{
	Super::BeginPlay();	

	SetActorLocationAndRotation(NewLocation, NewRotation, false, 0, ETeleportType::None);
}

