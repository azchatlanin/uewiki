#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateActorAroundPlayer_CPP.generated.h"

UCLASS()
class WIKI_API ARotateActorAroundPlayer_CPP : public AActor
{
	GENERATED_BODY()
	ARotateActorAroundPlayer_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	

public:	
	UPROPERTY(EditAnywhere, Category = Movement)
	float AngleAxis;

	UPROPERTY(EditAnywhere, Category = Movement)
	FVector Dimensions;

	UPROPERTY(EditAnywhere, Category = Movement)
	FVector AxisVector;

	UPROPERTY(EditAnywhere, Category = Movement)
	float Multiplier;
};
