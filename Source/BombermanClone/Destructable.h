// BomberBot 3D Game can not be copied and/or distributed without the express  permission of Evgheni Feldman(phillzzzz@gmail.com)

#pragma once

#include "CoreMinimal.h"
#include "GameInterraction.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Destructable.generated.h"

UCLASS()
class BOMBERMANCLONE_API ADestructable : public AActor, public IGameInterraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructable();

	UFUNCTION(BlueprintNativeEvent, Category = GameInterraction)
		void destroyBombVictim();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
