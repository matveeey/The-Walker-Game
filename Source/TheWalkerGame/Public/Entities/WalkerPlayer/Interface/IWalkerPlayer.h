#pragma once

#include "GameFramework/Actor.h"
#include "IWalkerPlayer.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)

class UIWalkerPlayer : public UInterface
{
    GENERATED_BODY()
};

class IIWalkerPlayer
{
    GENERATED_BODY()

public:
    UFUNCTION()
    virtual void CollectItem(TSubclassOf<AActor> ItemClass, AActor* CollectedItem) = 0; // Handle item collection
    UFUNCTION()
    virtual void MoveForward(float Value) = 0;
    UFUNCTION()
    virtual void MoveRight(float Value) = 0;
};