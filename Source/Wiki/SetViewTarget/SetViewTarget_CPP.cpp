#include "SetViewTarget_CPP.h"
#include "Kismet/GameplayStatics.h"

ASetViewTarget_CPP::ASetViewTarget_CPP()
{

}

void ASetViewTarget_CPP::BeginPlay()
{
	Super::BeginPlay();	

	// Find the actor that handles control for the local player.
	class APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	
	// Для увидения расскоментировать
	// устанавливает камеру сразу
	// PlayerController->SetViewTarget(MyActor);
}


