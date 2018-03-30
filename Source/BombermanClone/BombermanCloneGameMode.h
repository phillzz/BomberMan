// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameGrid.h"
#include "GameFramework/GameModeBase.h"
#include "BombermanCloneGameMode.generated.h"

UCLASS(minimalapi)
class ABombermanCloneGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABombermanCloneGameMode();
	
	//TODO: Flow Control
	void SpawnGrid();
	void ResetGame();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "GameGrid")
		TSubclassOf<class AGameGrid> BPGameGrid;
};



