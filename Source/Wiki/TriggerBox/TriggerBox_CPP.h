#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TriggerBox_CPP.generated.h"

UCLASS()
class WIKI_API ATriggerBox_CPP : public ATriggerBox
{
	GENERATED_BODY()
	ATriggerBox_CPP();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);	
};
