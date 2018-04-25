// BomberBot 3D Game can not be copied and/or distributed without the express  permission of Evgheni Feldman(phillzzzz@gmail.com)

#include "Destructable.h"


// Sets default values
ADestructable::ADestructable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADestructable::destroyBombVictim_Implementation()
{
	Destroy();
}

// Called when the game starts or when spawned
void ADestructable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestructable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

