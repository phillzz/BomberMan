// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Character.h"
#include "Bomb.h"
#include "GameGrid.h"
#include "BombermanCloneCharacter.generated.h"

UCLASS(Blueprintable)
class ABombermanCloneCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABombermanCloneCharacter();

	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	
	//Internal use functions
	UFUNCTION()
		void ResetActorDefaults();
	UFUNCTION()
		void OnTimerEnd();
	//Player Controller Related Functions
	UFUNCTION(BlueprintCallable, Category = PlayerController)
		void GameActionCall();
	//Bomb Related Functions
	UFUNCTION(BlueprintCallable, Category = Bomb)
		void ResetBombDefaults(int32 CurrentBombCount);
	UFUNCTION(BlueprintCallable, Category = Bomb)
		void SpawnBomb();
	UFUNCTION(BlueprintCallable, Category = Bomb)
		void SpawnRemoteBomb();
	UFUNCTION(BlueprintCallable, Category = Bomb)
		void DestroyRemoteBomb();
	UFUNCTION(BlueprintPure, Category = Bomb)
		FTransform SpawnTransform();

	UPROPERTY()
		FTimerHandle LoopTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bomb)
		int32 BombCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bomb)
		float BombRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bomb)
		bool bRemoteActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bomb)
		bool bFirstClick;
	UPROPERTY(EditAnywhere, Category = Bomb)
		TSubclassOf<class ABomb> Bomb;
	UPROPERTY(EditAnywhere, Category = Bomb)
		TSubclassOf<class ABomb> RemoteBomb;
};

