#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WikiPawn_CPP.generated.h"

UCLASS()
class WIKI_API AWikiPawn_CPP : public APawn
{
	GENERATED_BODY()
	AWikiPawn_CPP();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	
};
