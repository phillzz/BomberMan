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
	// Sets default values for this actor's properties
	AGameGrid();
	void Reset();

	UFUNCTION(BlueprintPure, Category = GameMode)
		FTransform GridSizeToLocation(int32 ID);

	TSubclassOf<AGameGrid> BP_GameGrid;;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
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
