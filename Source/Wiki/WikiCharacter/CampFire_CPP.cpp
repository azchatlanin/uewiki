#include "CampFire_CPP.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"

ACampFire_CPP::ACampFire_CPP()
{
	BoxComponent = CreateDefaultSubobject<class UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(50.0f,50.0f,50.0f));
	RootComponent = BoxComponent;

	Fire = CreateDefaultSubobject<class UParticleSystemComponent>(TEXT("Fire"));
	Fire->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Fire->SetupAttachment(RootComponent);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ACampFire_CPP::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &ACampFire_CPP::OnOverlapEnd);
}

void ACampFire_CPP::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr ) && (OtherActor != this) && (OtherComp != nullptr))
	{
		Character = Cast<class AActor>(OtherActor);
		Hit = SweepResult;
		GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ACampFire_CPP::ApplyFireDamage, 2.2f, true, 0.0f);
	}
}

void ACampFire_CPP::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
  GetWorldTimerManager().ClearTimer(FireTimerHandle);
}

void ACampFire_CPP::ApplyFireDamage()
{
	UE_LOG(LogTemp, Warning, TEXT("ApplyFireDamage"));
	UGameplayStatics::ApplyPointDamage(Character, 200.0f, GetActorLocation(), Hit, nullptr, this, UDamageType::StaticClass());
}


