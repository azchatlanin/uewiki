#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugLogger_CPP.generated.h"

UCLASS()
class WIKI_API ADebugLogger_CPP : public AActor
{
	GENERATED_BODY()
	ADebugLogger_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	
};
