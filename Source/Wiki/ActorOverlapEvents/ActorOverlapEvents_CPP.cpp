#define printV(data) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Orange, FString::Printf(TEXT("Vector: %s"), data));

#include "ActorOverlapEvents_CPP.h"
#include "Components/CapsuleComponent.h"

AActorOverlapEvents_CPP::AActorOverlapEvents_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<class UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	TriggerCapsule = CreateDefaultSubobject<class UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(300.f, 300.f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
  TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AActorOverlapEvents_CPP::OnOverlapBegin); 
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &AActorOverlapEvents_CPP::OnOverlapEnd);

	bDown = false;
}

void AActorOverlapEvents_CPP::BeginPlay()
{
	Super::BeginPlay();	 
}

void AActorOverlapEvents_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	// printV(*CurrentLocation.ToString());
	
	if (CurrentLocation.Z > 400.f) 
	{		
		bDown = true;
	}
	if (CurrentLocation.Z < -10.f) 
	{
		bDown = false;
	}

	if (bDown) 
	{
		CurrentLocation.Z -= 1.f;
	} 
	else
	{
		CurrentLocation.Z += 1.f;
	}

	SetActorLocation(CurrentLocation);
}

void AActorOverlapEvents_CPP::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
} 

void AActorOverlapEvents_CPP::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap End"));
}

