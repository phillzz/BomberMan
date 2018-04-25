// BomberBot 3D Game can not be copied and/or distributed without the express  permission of Evgheni Feldman(phillzzzz@gmail.com)

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameInterraction.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameInterraction : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMANCLONE_API IGameInterraction
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	void destroyBombVictim();
	
};
