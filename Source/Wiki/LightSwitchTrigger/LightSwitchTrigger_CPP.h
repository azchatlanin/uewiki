#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitchTrigger_CPP.generated.h"

UCLASS()
class WIKI_API ALightSwitchTrigger_CPP : public AActor
{
	GENERATED_BODY()
	ALightSwitchTrigger_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere, Category = LightSwitch)
	class UPointLightComponent* PointLight;

	UPROPERTY(VisibleAnywhere, Category = LightSwitch)
	class USphereComponent* LightSphere;

	UPROPERTY(VisibleAnywhere, Category = LightSwitch)
	float LightIntensity;
	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void ToggleLight();
};
