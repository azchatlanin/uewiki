#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DisableActor_CPP.generated.h"

UCLASS()
class WIKI_API ADisableActor_CPP : public AActor
{
	GENERATED_BODY()
	ADisableActor_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	
};
