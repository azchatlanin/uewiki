#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwitchActorMaterial_CPP.generated.h"

UCLASS()
class WIKI_API ASwitchActorMaterial_CPP : public AActor
{
	GENERATED_BODY()
	ASwitchActorMaterial_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* OnMaterial;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* OffMaterial;

	UPROPERTY()
	class UBoxComponent* MyBoxComponent;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
