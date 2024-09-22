#include "TheWalkerGame/Public/Entities/WalkerPlayer/WalkerPlayer.h"
#include "GameFramework/InputSettings.h"

AWalkerPlayer::AWalkerPlayer()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AWalkerPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // // Bind movement controls
    // FInputActionBinding Binding;
    // Binding.Action = FName("MoveForward");
    // Binding.EPress = EInputEvent::IE_Pressed;
    // Binding.bConsumeInput = true;

    // PlayerInputComponent->BindAction(Binding, IE_Pressed, this, &AWalkerPlayer::MoveForward);

    // Binding.Action = FName("MoveRight");
    // Binding.EPress = EInputEvent::IE_Pressed;
    // Binding.bConsumeInput = true;

    // PlayerInputComponent->BindAction(Binding, IE_Pressed, this, &AWalkerPlayer::MoveRight);
}

void AWalkerPlayer::BeginPlay()
{
    Super::BeginPlay();
}

void AWalkerPlayer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Update WalkerPlayer movement
    // if (Controller != nullptr && Controller->GetPlayerState<APlayerState>()->IsMoving())
    // {
    //     Move(Controller->GetPlayerState<APlayerState>()->GetMovementDirection() * DeltaTime);
    // }
}

void AWalkerPlayer::CollectItem(TSubclassOf<AActor> ItemClass, AActor* CollectedItem)
{
    UE_LOG(LogTemp, Warning, TEXT("[DEBUG] collect itm"));

    if (OnHandleCollectableEvent.IsBound())
    {
        OnHandleCollectableEvent.Broadcast(this);
    }
}

void AWalkerPlayer::MoveForward(float Value)
{
    UE_LOG(LogTemp, Warning, TEXT("[DEBUG] move fwd %s"), *FString::SanitizeFloat(Value));
}

void AWalkerPlayer::MoveRight(float Value)
{
    UE_LOG(LogTemp, Warning, TEXT("[DEBUG] move rgt %s"), *FString::SanitizeFloat(Value));
}
