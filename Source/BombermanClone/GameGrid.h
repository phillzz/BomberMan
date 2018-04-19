// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UndestructableObstacle.h"
#include <vector>
#include "GameGrid.generated.h"

UCLASS()
class BOMBERMANCLONE_API AGameGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	AGameGrid();

	virtual void Tick(float DeltaTime) override;

	float CellSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 iSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 jSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 GridDimensions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 DestructablesAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		TArray<int32> LocationToGridArray;
		

	UFUNCTION(BlueprintPure, Category = GameGrid)
		FTransform GridSizeToLocation(int32 ID);
	UFUNCTION(blueprintcallable, Category = GameGrid)
		void SetUnbreakablesID();
	UFUNCTION(blueprintcallable, Category = GameGrid)
		void SetBreakablesID();
	UFUNCTION(blueprintcallable, Category = GameGrid)
		void Debug();

protected:

	virtual void BeginPlay() override;

private: 
	//std::vector<int32> LocationToGrid;
	// temp
	int32 breakablesCounter = 0;
	int32 UnbreakablesCounter = 0;
	

	void Reset();
	void ResizeGrid();
	void SetSpawnPoints();
};