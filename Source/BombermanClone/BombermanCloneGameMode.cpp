// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BombermanCloneGameMode.h"
#include "BombermanClonePlayerController.h"
#include "BombermanCloneCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABombermanCloneGameMode::ABombermanCloneGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABombermanClonePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}