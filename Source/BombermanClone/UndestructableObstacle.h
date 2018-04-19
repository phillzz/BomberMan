// BomberBot 3D Game can not be copied and/or distributed without the express  permission of Evgheni Feldman(phillzzzz@gmail.com)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UndestructableObstacle.generated.h"

UCLASS()
class BOMBERMANCLONE_API AUndestructableObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUndestructableObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
