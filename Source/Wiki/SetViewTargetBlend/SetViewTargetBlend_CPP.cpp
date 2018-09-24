#include "SetViewTargetBlend_CPP.h"
#include "Kismet/GameplayStatics.h"

// Перемещаем камеру на нового актора

ASetViewTargetBlend_CPP::ASetViewTargetBlend_CPP()
{

}

void ASetViewTargetBlend_CPP::BeginPlay()
{
	Super::BeginPlay();	

	// Find the actor that handles control for the local player.
	class APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	
	// Для увидения расскоментировать
	// устанавливает камеру по времени
	// PlayerController->SetViewTargetWithBlend(MyActor, 2.f);
}

