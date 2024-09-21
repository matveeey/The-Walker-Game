#include "TheWalkerGame/Public/WalkerPlayer/WalkerPlayer.h"
#include "GameFramework/InputSettings.h"

AWalkerPlayer::AWalkerPlayer()
{
    // Set this character to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;

    // ... (other initialization code)
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

}

void AWalkerPlayer::MoveForward(float Value)
{
    // Forward movement code here
}

void AWalkerPlayer::MoveRight(float Value)
{
    // Right movement code here
}
