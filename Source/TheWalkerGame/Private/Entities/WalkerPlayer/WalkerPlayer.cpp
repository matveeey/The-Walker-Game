#include "TheWalkerGame/Public/Entities/WalkerPlayer/WalkerPlayer.h"
#include "GameFramework/InputSettings.h"

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

    if (OnHandleCollectableEvent.IsBound())
    {
        OnHandleCollectableEvent.Broadcast(this);
    }
}
