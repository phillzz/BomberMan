// BomberBot 3D Game can not be copied and/or distributed without the express  permission of Evgheni Feldman(phillzzzz@gmail.com)

#pragma once

#include "CoreMinimal.h"
#include "GameInterraction.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Destructable.h"
#include "Pickups.h"
#include "vector.h"
#include "Bomb.generated.h"

UCLASS()
class BOMBERMANCLONE_API ABomb : public AActor, public IGameInterraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

	virtual void Tick(float DeltaTime) override;
	void SetBombRange(float currentRange);
	UFUNCTION(BlueprintNativeEvent, Category = GameInterraction)
		void destroyBombVictim();
	UFUNCTION(blueprintcallable, Category = Bomb)
		void CheckForVictims();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	float DefaultBombRange = 300.f;

	//TODO: Implemebt those fuctions
	FVector GetRichLineStart();
	const FHitResult GetVictims();

};