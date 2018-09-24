#include "RegisterHit_CPP.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"


ARegisterHit_CPP::ARegisterHit_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<class UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetSimulatePhysics(true);
	BoxComponent->SetNotifyRigidBodyCollision(true);
	BoxComponent->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	BoxComponent->OnComponentHit.AddDynamic(this, &ARegisterHit_CPP::OnHit);

	RootComponent = BoxComponent;
}

void ARegisterHit_CPP::BeginPlay()
{
	Super::BeginPlay();
}

void ARegisterHit_CPP::OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherActor->GetName() != "Floor")
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Green, FString::Printf(TEXT("Hit: %s"), *OtherActor->GetName()));
	}
}


