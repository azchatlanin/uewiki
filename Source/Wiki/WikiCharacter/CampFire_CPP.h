#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CampFire_CPP.generated.h"

UCLASS()
class WIKI_API ACampFire_CPP : public AActor
{
	GENERATED_BODY()
	ACampFire_CPP();

public:	
	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* Fire;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComponent;

	struct FTimerHandle FireTimerHandle;

	UPROPERTY(EditAnywhere)
	class AActor* Character;

	UPROPERTY(EditAnywhere)
	struct FHitResult Hit;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void ApplyFireDamage();
};
