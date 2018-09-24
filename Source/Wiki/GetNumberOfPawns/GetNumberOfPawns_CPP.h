#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GetNumberOfPawns_CPP.generated.h"

UCLASS()
class WIKI_API AGetNumberOfPawns_CPP : public AActor
{
	GENERATED_BODY()
	AGetNumberOfPawns_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	
};
