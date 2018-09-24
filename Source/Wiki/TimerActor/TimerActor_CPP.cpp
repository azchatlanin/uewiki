#include "TimerActor_CPP.h"

ATimerActor_CPP::ATimerActor_CPP()
{

}

void ATimerActor_CPP::BeginPlay()
{
	Super::BeginPlay();	

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ATimerActor_CPP::RepeatingFunction, 3.0f, true, 2.0f);
}

void ATimerActor_CPP::RepeatingFunction()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hello Timer"));
}

