#include "DebugDraw_CPP.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

// Отрисовка нужных объектов для дебага на сцене

ADebugDraw_CPP::ADebugDraw_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	Loc1 = FVector(0.f, 0.f, 600.f);
	Loc2 = FVector(0.f, -600.f, 600.f);
	Loc3 = FVector(0.f, 600.f, 600.f);
	Loc4 = FVector(-100.f, 0.f, 600.f);
	Loc5 = FVector(-400.f, 600.f, 600.f);

	Box = FBox(FVector(0.f, 0.f, 0.f), FVector(200.f, 200.f, 200.f));
	Transform.SetLocation(FVector(0.f, 500.f, 600.f));
}

void ADebugDraw_CPP::BeginPlay()
{
	Super::BeginPlay();

	// Путпурная точка (но она большая:))
	DrawDebugPoint(GetWorld(), Loc1, 200.f, FColor::Magenta, true, 5000.f);
	
	// Голубая сфера
	DrawDebugSphere(GetWorld(), Loc2, 200.f, 26, FColor::Blue, true, 5000.f, 0, 2);
	
	// Синий круг с крестом
	DrawDebugCircle(GetWorld(), Loc4, 200.f, 50, FColor::Blue, true, 5000.f, 0, 10);
	
	// Черный ящик
	DrawDebugSolidBox(GetWorld(), Box, FColor::Black, Transform, true, 5000.f);
	
	// Пурпурный каркас ящика
	DrawDebugBox(GetWorld(), Loc5, FVector(100.f, 100.f, 100.f), FColor::Purple, true, 5000.f, 0, 10);
	
	// Желтая линия
	DrawDebugLine(GetWorld(), Loc2, Loc3, FColor::Yellow, true, 5000.f, 0, 10);
	
	// Красная срелка
	DrawDebugDirectionalArrow(GetWorld(), FVector(-300.f, 600.f, 600.f), FVector(-300.f, -600.f, 600.f), 120.f, FColor::Red, true, 5000.f, 0, 5.f);	
	
	// Зеленое перекрестие на небе
	DrawDebugCrosshairs(GetWorld(), FVector(0.f, 0.f, 1000.f), FRotator(0.f, 0.f, 0.f), 500.f, FColor::Green, true, 5000.f, 0);
}

