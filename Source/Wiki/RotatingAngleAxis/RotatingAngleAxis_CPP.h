#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingAngleAxis_CPP.generated.h"

UCLASS()
class WIKI_API ARotatingAngleAxis_CPP : public AActor
{
	GENERATED_BODY()
	ARotatingAngleAxis_CPP();

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
