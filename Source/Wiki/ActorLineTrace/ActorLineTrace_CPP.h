#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorLineTrace_CPP.generated.h"

UCLASS()
class WIKI_API AActorLineTrace_CPP : public AActor
{
	GENERATED_BODY()
	AActorLineTrace_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Cube1;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Cube2;
};
