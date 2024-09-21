// WalkerPlayer.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Interface/IWalkerPlayer.h"

#include "WalkerPlayer.generated.h"

UCLASS()
class AWalkerPlayer : public ACharacter, public IIWalkerPlayer
{
    GENERATED_BODY()

public:
    AWalkerPlayer();

protected:
    // Called when the game starts or when re-spawning
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    virtual void CollectItem(TSubclassOf<AActor> ItemClass, AActor* CollectedItem) override;
    virtual void MoveForward(float Value) override;
    virtual void MoveRight(float Value) override;
};
