#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WikiCharacter_CPP.generated.h"

UCLASS()
class WIKI_API AWikiCharacter_CPP : public ACharacter
{
	GENERATED_BODY()
	AWikiCharacter_CPP();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Ball, meta = (AllowPrivateAccess = "true"))
	class TSubclassOf<class UWikiCharacterUserWidget_CPP> WikiCharacterUI_BP;

public:
  class UWikiCharacterUserWidget_CPP *Widget;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
};
