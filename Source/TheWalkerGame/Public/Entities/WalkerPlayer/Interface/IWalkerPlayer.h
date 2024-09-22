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
    virtual void CollectItem() = 0; // Handle item collection
};