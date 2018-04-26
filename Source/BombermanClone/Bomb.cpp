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
	//TEMP
	CheckForVictims();
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ABomb::GetRichLineStart()
{
	FVector Location = GetActorLocation();
	return FVector();
}

const FHitResult ABomb::GetVictims()
{
	return FHitResult();
}

void ABomb::CheckForVictims()
{
	TArray<FHitResult> HitResults;
	FHitResult HitData(ForceInit);
	
	FCollisionObjectQueryParams ObjectList;
		ObjectList.AddObjectTypesToQuery(ECC_Pawn);
		ObjectList.AddObjectTypesToQuery(ECC_WorldDynamic);
		ObjectList.AddObjectTypesToQuery(ECC_WorldStatic);
	
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("TraceParams")), false, this);

	FVector Location = GetActorLocation();
		GetWorld()->LineTraceMultiByObjectType(HitResults, GetRichLineStart(), FVector(Location.X - DefaultBombRange, Location.Y, Location.Z), ObjectList, TraceParams);
		GetWorld()->LineTraceMultiByObjectType(HitResults, GetRichLineStart(), FVector(Location.X + DefaultBombRange, Location.Y, Location.Z), ObjectList, TraceParams);
		GetWorld()->LineTraceMultiByObjectType(HitResults, GetRichLineStart(), FVector(Location.X, Location.Y - DefaultBombRange, Location.Z), ObjectList, TraceParams);
		GetWorld()->LineTraceMultiByObjectType(HitResults, GetRichLineStart(), FVector(Location.X, Location.Y + DefaultBombRange, Location.Z), ObjectList, TraceParams);
	
	for (int i = 0; i < HitResults.Num(); ++i)
	{
		HitData = HitResults[i];
		AActor* FoundActor = HitData.GetActor();
		//Check For if hit results not empty
		if (!FoundActor)
		{
			UE_LOG(LogTemp, Error, TEXT("Hit Results Faild!"));
			return;
		}
		//Send Message to pawn
		if (FoundActor->IsA(APawn::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Bomb: Pawn Detect"));
			/*
			if (FoundActor->GetClass()->ImplementsInterface(UGameInterraction::StaticClass()))
				IGameInterraction::Execute_destroyBombVictim(FoundActor);
			*/
		}
		if (HitData.GetActor()->IsA(ABomb::StaticClass())) //&& ABomb::StaticClass()->ImplementsInterface(InteractionLogic::StaticClass()))
		{
			//TODO: Send interface message destroy victim
			UE_LOG(LogTemp, Warning, TEXT("Bomb: Bomb Detect"));

		}
		if (HitData.GetActor()->IsA(ADestructable::StaticClass())) // && ADestructable::StaticClass()->ImplementsInterface(UBombermanInteractionInterface::StaticClass()))
		{
			//TODO: Send interface message destroy victim
			UE_LOG(LogTemp, Warning, TEXT("Bomb: Destructable Detect"));
		}
		if (HitData.GetActor()->IsA(APickups::StaticClass())) // && APickups::StaticClass()->ImplementsInterface(UBombermanInteractionInterface::StaticClass()))
		{
			//TODO: Send interface message destroy victim
			UE_LOG(LogTemp, Warning, TEXT("Bomb: Pickup Detect"));
		}
	}
}


void ABomb::SetBombRange(float currentRange)
{
	DefaultBombRange = currentRange;
}

void ABomb::destroyBombVictim_Implementation()
{
	Destroy();
}
