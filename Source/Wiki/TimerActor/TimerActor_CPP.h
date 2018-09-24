#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerActor_CPP.generated.h"

UCLASS()
class WIKI_API ATimerActor_CPP : public AActor
{
	GENERATED_BODY()
	ATimerActor_CPP();

protected:
	virtual void BeginPlay() override;	

public:	
	void RepeatingFunction();	

public:
	struct FTimerHandle TimerHandle;
};
