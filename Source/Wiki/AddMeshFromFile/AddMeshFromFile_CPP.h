#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AddMeshFromFile_CPP.generated.h"

UCLASS()
class WIKI_API AAddMeshFromFile_CPP : public AActor
{
	GENERATED_BODY()
	AAddMeshFromFile_CPP();

protected:
	virtual void BeginPlay() override;
};
