// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGrid.h"
#include "BombermanCloneGameMode.h"

// Sets default values
AGameGrid::AGameGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Reset();
}

void AGameGrid::Reset()
{
	iSize = 1;
	jSize = 1;
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
	//Vector
	//LocationToGrid.resize(GridDimensions*GridDimensions);
}

// Functions Defenition
void AGameGrid::SetUnbreakablesID()
{
	for (iSize = 1; iSize < GridDimensions - 1; iSize = iSize + 2)
	{
		for (jSize = 1; jSize < GridDimensions - 1; jSize = jSize +2)
		{
			LocationToGridArray[iSize * GridDimensions + jSize] = 1;
			UnbreakablesCounter = UnbreakablesCounter + 1;
		}
	}
}

void AGameGrid::SetBreakablesID()
{
	//Each Second element from second row and column fill with breakables
	for (iSize = 0; iSize < GridDimensions; ++iSize)
	{
		for (jSize = 0; jSize < GridDimensions; ++jSize)
		{
			//Recieve ID from location on grid
			if (LocationToGridArray[iSize * GridDimensions + jSize] == 0)
			{
				LocationToGridArray[iSize * GridDimensions + jSize] = 2;
				breakablesCounter = breakablesCounter + 1;
			}
		}	
	}
	// Randomly delete few breakables in each row
	for (iSize = 0; iSize < GridDimensions; ++iSize)
	{
		for (jSize = 0; jSize < GridDimensions; ++jSize)
		{
			//Randomizer
			int32 RandElem = rand() % (DestructablesAmount * DestructablesAmount);
			if (LocationToGridArray[iSize * GridDimensions + jSize] == 2 && RandElem > DestructablesAmount)
			{
				LocationToGridArray[iSize * GridDimensions + jSize] = 0;
				breakablesCounter = breakablesCounter - 1;
			}
		}
	}
	//Clear first 4 cells for player #1 start position
	for (int32 i = 0; i < 4; ++i)
	{
		LocationToGridArray[i] = 0;
	}
	//Clear last 4 cells for player #2 start position
	for (int32 i = sizeof(LocationToGridArray) / sizeof(LocationToGridArray[0]); i > (sizeof(LocationToGridArray) / sizeof(LocationToGridArray[0])) - 4; --i)
	{
		LocationToGridArray[i] = 0;
	}
}

void AGameGrid::SetSpawnPoints()
{
	//ToDo implement spawning
	LocationToGridArray[0] = 3;
	

}

void AGameGrid::Debug()
{
	// Check is vector resized
	UE_LOG(LogTemp, Warning, TEXT("Grid Array Size: %d"), sizeof(LocationToGridArray) / sizeof(LocationToGridArray[0]));
	// Check is breakables spawned
	UE_LOG(LogTemp, Warning, TEXT("Number of Breakables: %d"), breakablesCounter);
	// Check is unbrakables spawned
	UE_LOG(LogTemp, Warning, TEXT("Number of Unbreakables: %d"), UnbreakablesCounter);

}

