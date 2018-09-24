#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SetActorLocationAndRotation_CPP.generated.h"

UCLASS()
class WIKI_API ASetActorLocationAndRotation_CPP : public AActor
{
	GENERATED_BODY()
	ASetActorLocationAndRotation_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = Location)
	FVector NewLocation;

	UPROPERTY(EditAnywhere, Category = Location)
	FQuat NewRotation;	
};
