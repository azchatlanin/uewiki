#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateAroundVector_CPP.generated.h"

UCLASS()
class WIKI_API ARotateAroundVector_CPP : public AActor
{
	GENERATED_BODY()
	ARotateAroundVector_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	float AngleAxis;
};
