#include "CreateStaticMesh_CPP.h"

ACreateStaticMesh_CPP::ACreateStaticMesh_CPP()
{
	StaticMesh = CreateDefaultSubobject<class UStaticMeshComponent>(TEXT("StaticMesh"));
}

void ACreateStaticMesh_CPP::BeginPlay()
{
	Super::BeginPlay();	
}


