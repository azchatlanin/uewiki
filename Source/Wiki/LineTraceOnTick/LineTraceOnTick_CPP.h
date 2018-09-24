#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LineTraceOnTick_CPP.generated.h"

UCLASS()
class WIKI_API ALineTraceOnTick_CPP : public AActor
{
	GENERATED_BODY()
	ALineTraceOnTick_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	

private:
	bool bDown;

public:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Cube;
};
