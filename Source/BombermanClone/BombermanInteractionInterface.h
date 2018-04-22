// BomberBot 3D Game can not be copied and/or distributed without the express  permission of Evgheni Feldman(phillzzzz@gmail.com)

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BombermanInteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBombermanInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class BOMBERMANCLONE_API IBombermanInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Bomb)
		bool CDestroyBomb();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Bomb)
		bool CDestroyVictim();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = PickUp)
		bool CPickedUp();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = PlayerController)
		bool CCallMoveForward(float AxisValue);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = PlayerController)
		bool CCallMoveRight(float AxisValue);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = PlayerController)
		bool CCallGameAction();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = GameState)
		bool CCurrentGameState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = GameState)
		bool CGameOver();
	
};
