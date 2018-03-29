// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BombermanCloneCharacter.generated.h"

UCLASS(Blueprintable)
class ABombermanCloneCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABombermanCloneCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

	void ResetActorDefaults();

	UFUNCTION(BlueprintCallable, Category = Bomb)
		void ResetBombDefaults(int32 CurrentBombCount);

	UFUNCTION(BlueprintPure, Category = Bomb)
		FTransform SpawnTransform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bomb)
		int32 BombCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bomb)
		float BombRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bomb)
		bool bRemoteActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bomb)
		bool bFirstClick;

private:
	

};

