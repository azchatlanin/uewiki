#include "ActorLineTrace_CPP.h"
#include "ConstructorHelpers.h"
#include "DrawDebugHelpers.h"

AActorLineTrace_CPP::AActorLineTrace_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	Cube1 = CreateDefaultSubobject<class UStaticMeshComponent>(TEXT("Cube1"));
	Cube2 = CreateDefaultSubobject<class UStaticMeshComponent>(TEXT("Cube2"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("StaticMesh'/Game/Cube.Cube'"));

	if (CubeAsset.Succeeded())
	{
		Cube1->SetStaticMesh(CubeAsset.Object);
		Cube2->SetStaticMesh(CubeAsset.Object);

		Cube1->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Cube2->SetRelativeLocation(FVector(200.0f, 0.0f, 300.0f));

		Cube1->SetWorldScale3D(FVector(1.f));
		Cube2->SetWorldScale3D(FVector(1.f));
	}

	RootComponent = Cube1;
	Cube2->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AActorLineTrace_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorLineTrace_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult OutHit;
	FVector Start = GetActorLocation();

	FVector ForwardVector = GetActorForwardVector();
	FVector End = ((ForwardVector * 500.f) + Start);
	FCollisionQueryParams CollisionParams;
	CollisionParams.bTraceComplex = true;
	// CollisionParams.AddIgnoredComponent(Cube);
	// CollisionParams.AddIgnoredComponent_LikelyDuplicatedRoot(Cube);
	CollisionParams.AddIgnoredActor(this);

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 5);

	// ВНИМАНИЕ
	// Эта штука работает когда у компонента есть какой то дочерний элемент и он отдалился отродителя
	// и  вот родитель при трассировке по отдалившемуся компоненту получает информацию
	// Я в редакторе добавил ребенка(белый куб в сцене) и отодвинул ручками от родителя 
	// Для получения эффекта опусти Cube2
	bool isHit = ActorLineTraceSingle(OutHit, Start, End, ECC_WorldStatic, CollisionParams);
	if(isHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("The Component Being Hit is: %s"), *OutHit.GetComponent()->GetName()));
	}
}

