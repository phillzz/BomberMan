// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BombermanCloneGameMode.h"
#include "GameGrid.h"
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
	
	ResetGame();
}


void ABombermanCloneGameMode::ResetGame()
{
	SpawnGrid();
}

void ABombermanCloneGameMode::SpawnGrid()
{

	if (BPGameGrid != NULL)
	{

		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			FVector Location(0.f, 0., 0.f);
			FRotator SpawnRotation;

			AGameGrid* const NewGameGrid = World->SpawnActor<AGameGrid>(BPGameGrid, Location, FRotator::ZeroRotator, SpawnParams);
		}

	}

}
