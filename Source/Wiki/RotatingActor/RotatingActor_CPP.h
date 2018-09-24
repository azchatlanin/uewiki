#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor_CPP.generated.h"

UCLASS()
class WIKI_API ARotatingActor_CPP : public AActor
{
	GENERATED_BODY()
	ARotatingActor_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	
};
