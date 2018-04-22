// BomberBot 3D Game can not be copied and/or distributed without the express  permission of Evgheni Feldman(phillzzzz@gmail.com)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BombermanInteractionInterface.h"
#include "Bomb.generated.h"

UCLASS()
class BOMBERMANCLONE_API ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

	virtual void Tick(float DeltaTime) override;
	void SetBombRange(float currentRange);
/*
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Bomb)
		bool DestroyBomb();
	virtual bool DestroyBomb_Implementation() override;
*/
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	float DefaultBombRange = 300.f;

	//TODO: Implemebt those fuctions
	FVector GetRichLineStart();
	FVector GetRichLineEnd();
	const FHitResult GetVictims();
};
