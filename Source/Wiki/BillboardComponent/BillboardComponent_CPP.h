#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BillboardComponent_CPP.generated.h"

UCLASS()
class WIKI_API ABillboardComponent_CPP : public AActor
{
	GENERATED_BODY()
	ABillboardComponent_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	

public:
	UPROPERTY(VisibleAnywhere)
	class UBillboardComponent *BillboardComponent;
};
