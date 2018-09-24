#include "BillboardComponent_CPP.h"
#include "Runtime/Engine/Classes/Components/BillboardComponent.h"

// 2D текстура, которая всегда отображается перед камерой как бы ты ни вертелся
// см. https://api.unrealengine.com/INT/API/Runtime/Engine/Components/UBillboardComponent/index.html

ABillboardComponent_CPP::ABillboardComponent_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	BillboardComponent = CreateDefaultSubobject<class UBillboardComponent>(TEXT("BillboardComponent"));
	// не скрываем и распростроняем на дочерние объекты у компонента
	BillboardComponent->SetHiddenInGame(false, true);

	RootComponent = BillboardComponent;
}

void ABillboardComponent_CPP::BeginPlay()
{
	Super::BeginPlay();
}

void ABillboardComponent_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

