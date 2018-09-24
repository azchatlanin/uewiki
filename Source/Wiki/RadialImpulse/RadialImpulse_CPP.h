#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RadialImpulse_CPP.generated.h"

UCLASS()
class WIKI_API ARadialImpulse_CPP : public AActor
{
	GENERATED_BODY()
	ARadialImpulse_CPP();

protected:
	virtual void BeginPlay() override;

private:
	void Burst();

public:
	struct FTimerHandle TimerHandle;
};
