// BomberBot 3D Game can not be copied and/or distributed without the express  permission of Evgheni Feldman(phillzzzz@gmail.com)

#include "UndestructableObstacle.h"


// Sets default values
AUndestructableObstacle::AUndestructableObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AUndestructableObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}
