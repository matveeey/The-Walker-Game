#pragma once

#include "ICollectable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)

class UICollectable : public UInterface
{
    GENERATED_BODY()
};

class IICollectable
{
    GENERATED_BODY()

public:
    virtual FString GetItemName() const = 0; // Return item name for display purposes

};