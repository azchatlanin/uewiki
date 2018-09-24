#include "RadialImpulse_CPP.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

ARadialImpulse_CPP::ARadialImpulse_CPP()
{
	
}

void ARadialImpulse_CPP::BeginPlay()
{
	Super::BeginPlay();	

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ARadialImpulse_CPP::Burst, 5.0f, false, 5.f);
}

void ARadialImpulse_CPP::Burst()
{
	TArray<FHitResult> OutHits;

	FVector MyLocation = GetActorLocation();

	FCollisionShape MyColSphere = FCollisionShape::MakeSphere(500.f);

	DrawDebugSphere(GetWorld(), GetActorLocation(), MyColSphere.GetSphereRadius(), 50, FColor::Cyan, true);

	bool isHit = GetWorld()->SweepMultiByChannel(OutHits, MyLocation, MyLocation, FQuat::Identity, ECC_WorldStatic, MyColSphere);

	if (isHit)
	{
		for (auto& Hit : OutHits)
		{
			UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>((Hit.GetActor())->GetRootComponent());

			if (MeshComp)
			{
				// alternivly you can use  ERadialImpulseFalloff::RIF_Linear for the impulse to get linearly weaker as it gets further from origin.
				MeshComp->AddRadialImpulse(GetActorLocation(), 500.f, 2000.f, ERadialImpulseFalloff::RIF_Constant, true);
			}
		}
	}
	Destroy();
}


