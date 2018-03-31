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
	
	UPROPERTY(EditAnywhere, Category = "GameGrid")
		TSubclassOf<class AGameGrid> BPGameGrid;

	virtual void BeginPlay() override;

private:
	void SpawnGrid();
	void ResetGame();
};



