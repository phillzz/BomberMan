// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BombermanCloneCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Materials/Material.h"
#include "Engine/World.h"

ABombermanCloneCharacter::ABombermanCloneCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	ResetActorDefaults();
}

void ABombermanCloneCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
	
}

void ABombermanCloneCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABombermanCloneCharacter::ResetActorDefaults()
{
	//Set Defaults
	BombCount = 1;
	BombRange = 300.f;
	bRemoteActive = false;
	bFirstClick = true;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
}

// Reset bomb to it default range and check for quantity
void ABombermanCloneCharacter::ResetBombDefaults(int32 CurrentBombCount)
{
	if (CurrentBombCount < 1)
	{
		BombCount = CurrentBombCount +1;
	}
	BombRange = 300.f;
}

FTransform ABombermanCloneCharacter::SpawnTransform()
{
	FTransform Transform = GetActorTransform();
	FVector SpawnLocation = Transform.GetLocation();
	FVector PredictedSpawnLocatin = Transform.GetLocation() + GetActorForwardVector() * 200.f;
	float DistanceToGridCellCenter = 100.f;

	int32 x = FMath::FloorToInt(((PredictedSpawnLocatin.X + DistanceToGridCellCenter) / 200.f));
	int32 y = FMath::FloorToInt(((PredictedSpawnLocatin.Y + DistanceToGridCellCenter) / 200.f));
	int32 ID = x * 13 + y;

	// Disable spawn at non grid location

	// Transform location to Grid ID
			
	// Disable spawn at non horizontal or vertical locations

	Transform.SetLocation(FVector(ID / 13 * 200.f, ID % 13 * 200.f, 0.f));
	
	return Transform;
}

