// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGrid.h"
#include "BombermanCloneGameMode.h"

// Sets default values
AGameGrid::AGameGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Reset();
}

void AGameGrid::Reset()
{
	GridDimensions = 13;
	DestructablesAmount = 3;
	CellSize = 200;

	ResizeGrid();
}

FTransform AGameGrid::GridSizeToLocation(int32 ID)
{
	FTransform Transform =GetActorTransform();
	Transform.SetLocation(FVector(ID / GridDimensions * 200.f, ID % GridDimensions * 200.f, 0.f));
	Transform.SetScale3D(FVector(2.f, 2.f, 2.f));
	return Transform;
}

// Called when the game starts or when spawned
void AGameGrid::BeginPlay()
{
	Super::BeginPlay();
	Debug();
}

// Called every frame
void AGameGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameGrid::ResizeGrid()
{
	LocationToGridArray.Init(0, GridDimensions*GridDimensions);
}

// Functions Defenition
void AGameGrid::SetUnbreakables()
{
	for (int32 i = 1; i < GridDimensions - 1; i = i + 2)
	{
		for (int32 j = 1; j < GridDimensions - 1; j = j +2)
		{
			LocationToGridArray[i * GridDimensions + j] = 1;
		}
	}
}

void AGameGrid::SetBreakables()
{
	//Fill grid except occupied cells by Breakables
	for (int32 i = 0; i < GridDimensions; ++i)
	{
		for (int32 j = 0; j < GridDimensions; ++j)
		{
			//Check if empty cell, then place a breakable
			if (LocationToGridArray[i * GridDimensions + j] == 0)
			{
				LocationToGridArray[i * GridDimensions + j] = 2;
			}
		}	
	}
	// Randomly delete few breakables in each row
	for (int32 i = 0; i < GridDimensions; ++i)
	{
		for (int32 j = 0; j < GridDimensions; ++j)
		{
			//Randomizer
			int32 RandElem = rand() % (DestructablesAmount * DestructablesAmount);
			if (LocationToGridArray[i * GridDimensions + j] == 2 && RandElem > DestructablesAmount)
			{
				LocationToGridArray[i * GridDimensions + j] = 0;
			}
		}
	}
	//Clear first 4 cells for player #1 start position
	for (int32 i = 0; i < 4; ++i)
	{
		LocationToGridArray[i] = 0;
	}
	//Clear last 4 cells for player #2 start position
	for (int32 i = GridDimensions * GridDimensions - 1; i > GridDimensions * GridDimensions - 5; --i)
	{
		LocationToGridArray[i] = 0;
	}
}

void AGameGrid::SetSpawnPoints()
{
	LocationToGridArray[0] = 3;
	LocationToGridArray[GridDimensions * GridDimensions - 1] = 3;
}

void AGameGrid::Debug()
{
	// Check is vector resized
	UE_LOG(LogTemp, Warning, TEXT("Grid Array Size: %d"), sizeof(LocationToGridArray) / sizeof(LocationToGridArray[0]));
}

