#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CollidingPawn_CPP.generated.h"

UCLASS()
class WIKI_API ACollidingPawn_CPP : public APawn
{
	GENERATED_BODY()
	ACollidingPawn_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	
	virtual class UPawnMovementComponent* GetMovementComponent() const override;

private:
	class UParticleSystemComponent* OurParticleSystem;
	class UPawnMovementComponent_CPP* OurMovementComponent;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);
	void ParticleToggle();
};
