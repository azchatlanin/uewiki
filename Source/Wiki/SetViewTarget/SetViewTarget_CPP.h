#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SetViewTarget_CPP.generated.h"

UCLASS()
class WIKI_API ASetViewTarget_CPP : public AActor
{
	GENERATED_BODY()
	ASetViewTarget_CPP();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	class AActor* MyActor;	
};
