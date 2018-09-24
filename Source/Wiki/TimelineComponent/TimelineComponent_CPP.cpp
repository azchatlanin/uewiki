#include "TimelineComponent_CPP.h"
#include "Components/TimelineComponent.h"

DEFINE_LOG_CATEGORY_STATIC(TimelineComponent_CPP, Warning, All);

ATimelineComponent_CPP::ATimelineComponent_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATimelineComponent_CPP::BeginPlay()
{
	Super::BeginPlay();
	
	if (CurveFloat)
	{
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;

		TimelineCallback.BindUFunction(this, FName("SetValue"));
		TimelineFinishedCallback.BindUFunction(this, FName("SetState"));

		Timeline = NewObject<class UTimelineComponent>(this, FName("CurveFloat"));
		Timeline->AddInterpFloat(CurveFloat, TimelineCallback);
		Timeline->SetTimelineFinishedFunc(TimelineFinishedCallback);
		Timeline->RegisterComponent();

		if(Timeline != nullptr) Timeline->PlayFromStart();
		// if(Timeline != nullptr) Timeline->Stop();
	}
}

void ATimelineComponent_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// if (Timeline != nullptr) Timeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
}
void ATimelineComponent_CPP::SetValue(float Value)
{
	UE_LOG(TimelineComponent_CPP, Warning, TEXT("Set Value: %f"), Value);
}
void ATimelineComponent_CPP::SetState()
{
	UE_LOG(TimelineComponent_CPP, Warning, TEXT("Set State"));
}

