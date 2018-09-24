#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugDraw_CPP.generated.h"

UCLASS()
class WIKI_API ADebugDraw_CPP : public AActor
{
	GENERATED_BODY()
	ADebugDraw_CPP();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = Locations)
	FVector Loc1;
	
	UPROPERTY(EditAnywhere, Category = Locations)
	FVector Loc2;
	
	UPROPERTY(EditAnywhere, Category = Locations)
	FVector Loc3;
	
	UPROPERTY(EditAnywhere, Category = Locations)
	FVector Loc4;
	
	UPROPERTY(EditAnywhere, Category = Locations)
	FVector Loc5;
	
	UPROPERTY(EditAnywhere, Category = Locations)
	FBox Box;

	UPROPERTY(EditAnywhere, Category = Locations)
	FTransform Transform;
};
