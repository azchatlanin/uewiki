#include "AddMeshFromFile_CPP.h"

AAddMeshFromFile_CPP::AAddMeshFromFile_CPP()
{
	class UStaticMeshComponent* Cylinder = CreateDefaultSubobject<class UStaticMeshComponent>(TEXT("Cylinder"));
	RootComponent = Cylinder;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("StaticMesh'/Game/Cylinder.Cylinder'"));

	if (CylinderAsset.Succeeded())
	{
		Cylinder->SetStaticMesh(CylinderAsset.Object);
		Cylinder->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		Cylinder->SetWorldScale3D(FVector(1.f));
	}
}

void AAddMeshFromFile_CPP::BeginPlay()
{
	Super::BeginPlay();
}

