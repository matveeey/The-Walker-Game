#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Interface/ICollectable.h"

#include "Collectable.generated.h"

UCLASS()
class ACollectable : public AActor, public IICollectable
{
    GENERATED_BODY()

public:
    ACollectable();

public:
    virtual const FString GetItemName() const override;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

};
