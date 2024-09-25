#include "TheWalkerGame/Public/GameMode/WalkerGameMode.h"
#include "TheWalkerGame/Public/Entities/WalkerPlayer/WalkerPlayer.h"

#include "GameFramework/PlayerController.h"

#include "TheWalkerGame/Public/Entities/Collectables/Collectable.h"

AWalkerGameMode::AWalkerGameMode()
{
}

void AWalkerGameMode::BeginPlay()
{
	Super::BeginPlay();

	APawn* PossessedPawn = GetPossessedPawn();
	if (IsValid(PossessedPawn))
	{
		AWalkerPlayer* WalkerPlayer = Cast<AWalkerPlayer>(PossessedPawn);
		if (IsValid(WalkerPlayer))
		{
			WalkerPlayer->OnHandleCollectableEvent.AddUFunction(this, FName("HandleCollectableEvent"));
		}
	}
}

void AWalkerGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWalkerGameMode::HandleCollectableEvent(const AActor* Collectable)
{
	const ACollectable* Item = Cast<ACollectable>(Collectable);
	if (Item)
	{
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] GameMode: received %s"), *Item->GetItemName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] GameMode: could not parse to ACollectable"));
	}

	// // Get player and collectable
	// class APlayer* Player = Cast<APlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	// if (Player && Player->GetPlayerState<UPlayerState>()->HasItemInInventory())
	// {
	//     // Handle item collection event here
	// }

	// // Get a list of all actors in the level
	// TArray<AActor*> Actors;
	// GetWorld()->GetActorsOfClass(Actors, ACollectable::StaticClass());

	// for (auto Act : Actors)
	// {
	//     class APlayer* Player = Cast<APlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	//     if (Player && Player->GetPlayerState<UPlayerState>()->HasItemInInventory())
	//     {
	//         // Handle item collection event here
	//         GetWorld()->GetTimerManager().ClearTimer(GetTimerHandle(ItemCollected));
	//     }
	// }
}

APawn* AWalkerGameMode::GetPossessedPawn()
{
	return GetWorld()->GetFirstPlayerController()->GetPawn();
}