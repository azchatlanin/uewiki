#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RegisterHit_CPP.generated.h"

UCLASS()
class WIKI_API ARegisterHit_CPP : public AActor
{
	GENERATED_BODY()
	ARegisterHit_CPP();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxComponent;

	UFUNCTION()
	void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
