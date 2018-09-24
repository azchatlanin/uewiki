#include "CameraDirector_CPP.h"
#include "Kismet/GameplayStatics.h"

ACameraDirector_CPP::ACameraDirector_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACameraDirector_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void ACameraDirector_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;
	TimeToNextCameraChange -= DeltaTime;
	
	if (TimeToNextCameraChange <= 0.0f)
	{
		TimeToNextCameraChange += TimeBetweenCameraChanges;

		//Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraTwo && (OurPlayerController->GetViewTarget() == CameraOne))
			{
				//Blend smoothly to camera two.
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
			else if (CameraOne)
			{
				//Cut instantly to camera one.
				OurPlayerController->SetViewTarget(CameraOne);
			}
		}
	}
}

