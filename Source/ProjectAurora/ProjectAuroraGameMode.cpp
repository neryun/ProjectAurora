// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectAuroraGameMode.h"
#include "ProjectAuroraPlayerController.h"
#include "ProjectAuroraCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectAuroraGameMode::AProjectAuroraGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AProjectAuroraPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/BP_Player"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Characters/BP_PlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}