// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BombermanCloneGameMode.generated.h"

UCLASS(minimalapi)
class ABombermanCloneGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABombermanCloneGameMode();
	
	virtual void BeginPlay() override;
	//Set defaults for game
	void RestartGame();

	//Save CurrentResults
	UFUNCTION(BlueprintCallable, Category = GameMode)
	void SaveScore(int32 Winner);

};



