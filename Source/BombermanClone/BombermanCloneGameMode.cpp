// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BombermanCloneGameMode.h"
#include "BombermanClonePlayerController.h"
#include "BombermanCloneCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABombermanCloneGameMode::ABombermanCloneGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABombermanClonePlayerController::StaticClass();

}

void ABombermanCloneGameMode::BeginPlay()
{
	Super::BeginPlay();
}


void ABombermanCloneGameMode::RestartGame()
{
	
}

void ABombermanCloneGameMode::SaveScore(int32 Winner)
{

}
