#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "WalkerGameMode.generated.h"

UCLASS()
class AWalkerGameMode : public AGameMode
{
    GENERATED_BODY()

public:
    AWalkerGameMode();

protected:
    // Called when the game starts or when re-spawning
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    UFUNCTION()
    void HandleCollectableEvent(AActor* Item);

    APawn* GetPossessedPawn();
};