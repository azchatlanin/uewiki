#include "WikiCharacter_CPP.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "./WikiCharacterUserWidget_CPP.h"

// Добавляем в QuickShooter.Build.cs "UMG", "Slate", "SlateCore"

AWikiCharacter_CPP::AWikiCharacter_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<class UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->RelativeLocation = FVector(0.f, 0.f, 0.f); 
	CameraComponent->bUsePawnControlRotation = true;
}

void AWikiCharacter_CPP::BeginPlay()
{
	Super::BeginPlay();	

	Widget = CreateWidget<class UWikiCharacterUserWidget_CPP>(GetWorld(), WikiCharacterUI_BP);
  if (Widget != NULL)
	{
		Widget->AddToViewport();
		UE_LOG(LogTemp, Warning, TEXT("Added Widget"));
		Widget->OnButtonClicked();
	}
}

void AWikiCharacter_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWikiCharacter_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AWikiCharacter_CPP::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWikiCharacter_CPP::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);	
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

float AWikiCharacter_CPP::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, class AActor * DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("DamageAmount: %f"), DamageAmount);
	Widget->StartAnimation();
	return DamageAmount;
}

void AWikiCharacter_CPP::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AWikiCharacter_CPP::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

