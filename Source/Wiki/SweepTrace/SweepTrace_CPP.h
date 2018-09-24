#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SweepTrace_CPP.generated.h"

UCLASS()
class WIKI_API ASweepTrace_CPP : public AActor
{
	GENERATED_BODY()
	ASweepTrace_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
