#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SetViewTargetBlend_CPP.generated.h"

UCLASS()
class WIKI_API ASetViewTargetBlend_CPP : public AActor
{
	GENERATED_BODY()
	ASetViewTargetBlend_CPP();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	class AActor* MyActor;
};
