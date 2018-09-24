#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimelineComponent_CPP.generated.h"

UCLASS()
class WIKI_API ATimelineComponent_CPP : public AActor
{
	GENERATED_BODY()
	ATimelineComponent_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Curve, meta = (AllowPrivateAccess = "true"))
	class UCurveFloat* CurveFloat;

private:
	class UTimelineComponent* Timeline;

private:
	UFUNCTION()
	void SetValue(float Value);

	UFUNCTION()
	void SetState();
};
