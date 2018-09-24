#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tuple_CPP.generated.h"

UCLASS()
class WIKI_API ATuple_CPP : public AActor
{
	GENERATED_BODY()
	ATuple_CPP();

protected:
	virtual void BeginPlay() override;

private:
	TTuple<float, int> GetTuple();
};
