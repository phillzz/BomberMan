// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameGrid.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BombermanClonePlayerController.generated.h"

UCLASS()
class ABombermanClonePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABombermanClonePlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};


