#include "SwitchActorMaterial_CPP.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"

ASwitchActorMaterial_CPP::ASwitchActorMaterial_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<class UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->SetupAttachment(RootComponent);
	RootComponent = MyMesh;

	MyBoxComponent = CreateDefaultSubobject<class UBoxComponent>(TEXT("My BoxComponent"));
	MyBoxComponent->InitBoxExtent(FVector(200.f, 200.f, 200.f));
	MyBoxComponent->SetCollisionProfileName("Trigger");
	MyBoxComponent->SetupAttachment(RootComponent);

	OnMaterial = CreateDefaultSubobject<class UMaterial>(TEXT("OnMaterial"));
	OffMaterial = CreateDefaultSubobject<class UMaterial>(TEXT("OffMaterial"));

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ASwitchActorMaterial_CPP::OnOverlapBegin);
}

void ASwitchActorMaterial_CPP::BeginPlay()
{
	Super::BeginPlay();	

	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(200.f, 200.f, 200.f), FColor::Green, true, -1, 0, 10.f);

	MyMesh->SetMaterial(0, OffMaterial);
}

void ASwitchActorMaterial_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASwitchActorMaterial_CPP::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if ((OtherActor != nullptr ) && (OtherActor != this) && (OtherComp != nullptr ) ) 
	{
		MyMesh->SetMaterial(0, OnMaterial);
	}
}

