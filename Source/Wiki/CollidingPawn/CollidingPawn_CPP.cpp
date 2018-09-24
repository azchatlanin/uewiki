#define printT(data) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Blue, data);

#include "CollidingPawn_CPP.h"
#include "Camera/CameraComponent.h"
#include "./PawnMovementComponent_CPP.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "ConstructorHelpers.h"
#include "GameFramework/SpringArmComponent.h"
#include "Particles/ParticleSystemComponent.h"

ACollidingPawn_CPP::ACollidingPawn_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	printT("PLEASE PRESS <G> FROM FIRE")

	class USphereComponent* SphereComponent = CreateDefaultSubobject<class USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	// Create and position a mesh component so we can see where our sphere is
	class UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<class UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<class UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		SphereVisual->SetWorldScale3D(FVector(0.8f));
	}

	// Create a particle system that we can activate or deactivate
	OurParticleSystem = CreateDefaultSubobject<class UParticleSystemComponent>(TEXT("MovementParticles"));
	OurParticleSystem->SetupAttachment(SphereVisual);
	OurParticleSystem->bAutoActivate = false;
	OurParticleSystem->SetRelativeLocation(FVector(-20.0f, 0.0f, 20.0f));
	static ConstructorHelpers::FObjectFinder<class UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	if (ParticleAsset.Succeeded())
	{
		OurParticleSystem->SetTemplate(ParticleAsset.Object);
	}

	// Use a spring arm to give the camera smooth, natural-feeling motion.
	class USpringArmComponent* SpringArm = CreateDefaultSubobject<class USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	// Create a camera and attach to our spring arm
	class UCameraComponent* Camera = CreateDefaultSubobject<class UCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	// Take control of the default player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create an instance of our movement component, and tell it to update our root component.
	OurMovementComponent = CreateDefaultSubobject<class UPawnMovementComponent_CPP>(TEXT("CustomMovementComponent"));
	OurMovementComponent->UpdatedComponent = RootComponent;
}

void ACollidingPawn_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void ACollidingPawn_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACollidingPawn_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("ParticleToggle", IE_Pressed, this, &ACollidingPawn_CPP::ParticleToggle);

	InputComponent->BindAxis("MoveForward", this, &ACollidingPawn_CPP::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACollidingPawn_CPP::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACollidingPawn_CPP::Turn);
}

class UPawnMovementComponent* ACollidingPawn_CPP::GetMovementComponent() const
{
	return OurMovementComponent;
}

void ACollidingPawn_CPP::MoveForward(float AxisValue)
{
	if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
	{
		OurMovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);
	}
}

void ACollidingPawn_CPP::MoveRight(float AxisValue)
{
	if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
	{
		OurMovementComponent->AddInputVector(GetActorRightVector() * AxisValue);
	}
}

void ACollidingPawn_CPP::Turn(float AxisValue)
{
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += AxisValue;
	SetActorRotation(NewRotation);
}

void ACollidingPawn_CPP::ParticleToggle()
{
	if (OurParticleSystem && OurParticleSystem->Template)
	{
		OurParticleSystem->ToggleActive();
	}
}

