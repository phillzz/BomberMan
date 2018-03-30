// Fill out your copyright notice in the Description page of Project Settings.

#include "GameGrid.h"


// Sets default values
AGameGrid::AGameGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Reset();
}

void AGameGrid::Reset()
{
	iSize = 0;
	jSize = 0;
	GridDimensions = 13;
	DestructablesAmount = 3;
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
	UE_LOG(LogTemp, Warning, TEXT("GameGridTemplate"));
}

// Called every frame
void AGameGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

