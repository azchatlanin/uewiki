#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorOverlapEvents_CPP.generated.h"

UCLASS()
class WIKI_API AActorOverlapEvents_CPP : public AActor
{
	GENERATED_BODY()
	AActorOverlapEvents_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	

public:
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
  class UCapsuleComponent* TriggerCapsule;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh;

	bool bDown;
};
