#include "TriggerBox_CPP.h"
#include "DrawDebugHelpers.h"

ATriggerBox_CPP::ATriggerBox_CPP()
{
  OnActorBeginOverlap.AddDynamic(this, &ATriggerBox_CPP::OnOverlapBegin);
  OnActorEndOverlap.AddDynamic(this, &ATriggerBox_CPP::OnOverlapEnd);
}

void ATriggerBox_CPP::BeginPlay()
{
	Super::BeginPlay();

  DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 5000.f, 0, 5);
}

void ATriggerBox_CPP::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
  if (OtherActor && OtherActor != this) 
  {
    if (GEngine) 
    { 
      GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, TEXT("Overlap Begin"));
      GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *OverlappedActor->GetName()));
    }
  }
}

void ATriggerBox_CPP::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
  if (OtherActor && OtherActor != this) 
  {
    if (GEngine) 
    {
      GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, TEXT("Overlap Ended"));
      GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));
    }
  }
}



