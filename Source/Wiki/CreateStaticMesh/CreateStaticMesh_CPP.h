#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreateStaticMesh_CPP.generated.h"

UCLASS()
class WIKI_API ACreateStaticMesh_CPP : public AActor
{
	GENERATED_BODY()
	ACreateStaticMesh_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh;
};
