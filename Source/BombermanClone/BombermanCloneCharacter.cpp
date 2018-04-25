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

void ABombermanCloneCharacter::destroyBombVictim_Implementation()
{
	Destroy();
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

	//TODO: check if the cell is empty
		// check span id if equal 0 then spawn.
	//Check if the cell id is near player location id
		//Check if bomb location id is near player id to prevent wrong spawn
	//Prevent non vertical or horizontal spawn
		// exclude from spawning on this directions
	UWorld* const World = GetWorld();
	if (ID == 0)
	{
		
	}
	Transform.SetLocation(FVector(ID / 13 * 200.f, ID % 13 * 200.f, 0.f));
	// Disable spawn at non horizontal or vertical locations
	
	
	return Transform;
}
//TODO: complete game action call event
void ABombermanCloneCharacter::GameActionCall()
{
	ABomb* CurrentBomb = nullptr;
	// Do we have bombs to place?
	if (BombCount >= 1)
	{
		//Check if player have remote bomb
		if (bRemoteActive)
		{	
			// If it is first click then spawn a remote bomb
			if (bFirstClick)
			{
				//TODO: check if the cell is empty
				//Check if the cell id is near player location id
				SpawnRemoteBomb(CurrentBomb);
				if (CurrentBomb != NULL)
				{	
					Bomb->GetDefaultObject<ABomb>()->SetBombRange(BombRange);
					BombCount = BombCount - 1;
					bFirstClick = false;
				}
			}
			// if it is not first click then destroy remote bomb
			else
			{
				//DestroyRemoteBomb();
			}
		}
		// if no, then spawn a usual bomb
		else 
		{
			//TODO: check if the cell is empty
			//Check if the cell id is near player location id
			SpawnBomb(CurrentBomb);
			if (CurrentBomb != NULL)
			{
				Bomb->GetDefaultObject<ABomb>()->SetBombRange(BombRange);
				BombCount = BombCount - 1;
				GetWorld()->GetTimerManager().SetTimer(LoopTimerHandle, this, &ABombermanCloneCharacter::OnTimerEnd, 1.f, false);
			}	
		}
	}
	// if this is first click then reset bomb count
	if (bFirstClick)
	{
		GetWorld()->GetTimerManager().SetTimer(LoopTimerHandle, this, &ABombermanCloneCharacter::OnTimerEnd, 1.f, false);
	}	
	// if it isn't first click then send message to detroy bomb
	else 
	{
		
		//DestroyBombMessage();
		/*
		if (Bomb->GetClass()->ImplementsInterface(UBombermanInteractionInterface::StaticClass()))
		{
			IBombermanInteractionInterface::Execute_FunctionName(Bomb);
		}
		*/
		ResetBombDefaults(BombCount);
		bFirstClick = true;
		bRemoteActive = false;
	}
}

void ABombermanCloneCharacter::SpawnBomb(ABomb* CurrentsBomb)
{

	if (Bomb != NULL)
	{
		UWorld* const World = GetWorld();
		if (World) 
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			FTransform Transform = SpawnTransform();
			FVector Location = Transform.GetLocation();

			ABomb* NewBomb = World->SpawnActor<ABomb>(Bomb, Location, FRotator::ZeroRotator, SpawnParams);
			CurrentsBomb = NewBomb;
		}
	}
}

void ABombermanCloneCharacter::SpawnRemoteBomb(ABomb* CurrentsBomb)
{
	if (RemoteBomb != NULL)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			FTransform Transform = SpawnTransform();
			FVector Location = Transform.GetLocation();

			ABomb* const NewRemoteBomb = World->SpawnActor<ABomb>(RemoteBomb, Location, FRotator::ZeroRotator, SpawnParams);
			UE_LOG(LogTemp, Warning, TEXT("RemoteBomb Online"));
		}
	}
}

void ABombermanCloneCharacter::DestroyRemoteBomb()
{
}

void ABombermanCloneCharacter::OnTimerEnd()
{
	ResetBombDefaults(BombCount);
}
