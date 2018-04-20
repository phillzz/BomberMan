// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UndestructableObstacle.h"
#include <vector>
#include <array>
#include "GameGrid.generated.h"

UCLASS()
class BOMBERMANCLONE_API AGameGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	AGameGrid();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = GameGrid)
		FTransform GridSizeToLocation(int32 ID);
	UFUNCTION(blueprintcallable, Category = GameGrid)
		void SetUnbreakables();
	UFUNCTION(blueprintcallable, Category = GameGrid)
		void SetBreakables();
	UFUNCTION(blueprintcallable, Category = GameGrid)
		void SetSpawnPoints();
	UFUNCTION(blueprintcallable, Category = GameGrid)
		void Debug();

	float CellSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 GridDimensions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 DestructablesAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		TArray<int32> LocationToGridArray;
		
protected:
	virtual void BeginPlay() override;

private: 
	void Reset();
	void ResizeGrid();
};