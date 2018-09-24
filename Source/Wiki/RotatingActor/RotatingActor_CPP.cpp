#include "RotatingActor_CPP.h"

// Пример ротации
// если посмотреть на сцену то там куб
// он устанавливается через редактор Add Component

ARotatingActor_CPP::ARotatingActor_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingActor_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatingActor_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FQuat QuatRotation = FQuat(FRotator(1.f, -1.f, 1.f));

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

	// ETeleportType::None - 

	// The below method causes a bug for the pitch value. The pitch value stops updating at 90 degrees
	// this is a known bug in the Unreal Engine. 
	// solution found by ue4 user nutellis https://answers.unrealengine.com/questions/591752/pitch-rotation-stucks-at-90-90-c.html

	// FRotator NewRotation = GetActorRotation();

	// NewRotation.Pitch += PitchValue;
	// NewRotation.Yaw += YawValue;
	// NewRotation.Roll += RollValue;
	
	// OR add values using the FRotator Add function
	// FRotator NewRotation = GetActorRotation().Add(PitchValue, YawValue, RollValue);


	// SetActorRotation(NewRotation);
}

