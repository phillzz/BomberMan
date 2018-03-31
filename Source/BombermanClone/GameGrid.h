// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameGrid.generated.h"

UCLASS()
class BOMBERMANCLONE_API AGameGrid : public AActor
{
	GENERATED_BODY()
	
public:	

	AGameGrid();

	UFUNCTION(BlueprintPure, Category = GameMode)
		FTransform GridSizeToLocation(int32 ID);

	void Reset();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 iSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 jSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 GridDimensions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameGrid)
		int32 DestructablesAmount;
};
