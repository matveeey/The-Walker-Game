#include "TheWalkerGame/Public/Entities/WalkerPlayer/WalkerPlayer.h"
#include "GameFramework/InputSettings.h"

#include "TheWalkerGame/Public/Entities/Collectables/Collectable.h"

AWalkerPlayer::AWalkerPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

// for now there would be internal inputs handling due to lack of time
void AWalkerPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Actions section
	PlayerInputComponent->BindAction(FName("CollectItem"), IE_Pressed, this, &AWalkerPlayer::CollectItem);
	
	// Axis section
	// PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AWalkerPlayer::MoveRight);
}

void AWalkerPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AWalkerPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWalkerPlayer::CollectItem()
{
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] collect itm"));

	TArray<AActor*> Items;
	GetOverlappingActors(Items, ACollectable::StaticClass());
	
	if (Items.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Collision detected. No ACollectables"));
		return;
	}
	
	for (const auto& Item : Items)
	{
		ACollectable* Collectable = Cast<ACollectable>(Item);
		
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] picking %s"), *Collectable->GetItemName());
		// Tell listeners that collecting has happened
		if (OnHandleCollectableEvent.IsBound())
		{
			OnHandleCollectableEvent.Broadcast(Item);
		}
	}
	
}
