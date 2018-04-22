// BomberBot 3D Game can not be copied and/or distributed without the express  permission of Evgheni Feldman(phillzzzz@gmail.com)

#include "Bomb.h"


// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ABomb::GetRichLineStart()
{
	return FVector();
}

FVector ABomb::GetRichLineEnd()
{
	return FVector();
}

const FHitResult ABomb::GetVictims()
{
	return FHitResult();
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABomb::SetBombRange(float currentRange)
{
	DefaultBombRange = currentRange;
}

/*
bool ABomb::DestroyBomb_Implementation()
{
	
	return true;
}
*/

