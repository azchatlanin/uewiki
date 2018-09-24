#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor_CPP.generated.h"

UCLASS()
class WIKI_API AFloatingActor_CPP : public AActor
{
	GENERATED_BODY()
	AFloatingActor_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:	
	float RunningTime;
	
	UPROPERTY(EditAnywhere, Category = Movement)
	float XValue;

	UPROPERTY(EditAnywhere, Category = Movement)
	float YValue;

	UPROPERTY(EditAnywhere, Category = Movement)
	float ZValue;		
};
