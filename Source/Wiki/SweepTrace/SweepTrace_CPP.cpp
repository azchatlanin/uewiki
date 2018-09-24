#include "SweepTrace_CPP.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

// Определение пересечения

ASweepTrace_CPP::ASweepTrace_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASweepTrace_CPP::BeginPlay()
{
	Super::BeginPlay();	

	TArray<FHitResult> OutHits;

	FVector Start = GetActorLocation();
	FVector End = GetActorLocation();

	FCollisionShape CollisionShape = FCollisionShape::MakeSphere(100.0f);

	DrawDebugSphere(GetWorld(), GetActorLocation(), CollisionShape.GetSphereRadius(), 50, FColor::Purple, true, 5000.f);

	bool isHit = GetWorld()->SweepMultiByChannel(OutHits, Start, End, FQuat::Identity, ECC_WorldStatic, CollisionShape);

	if (isHit)
	{
		for (auto& Hit : OutHits)
		{
			if (GEngine) 
			{
				GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Green, FString::Printf(TEXT("Hit Result Name: %s"), *Hit.Actor->GetName()));
				// GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Red, FString::Printf(TEXT("All Hit Information: %s"), *Hit.ToString()));
			}						
		}
	}
}

void ASweepTrace_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

