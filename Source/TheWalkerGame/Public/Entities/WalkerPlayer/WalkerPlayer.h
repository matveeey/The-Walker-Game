// WalkerPlayer.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// WalkerPlayer Interface

#include "Interface/IWalkerPlayer.h"

// Components
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"

#include "WalkerPlayer.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FHandleCollectableEventSignature, AActor*);

UCLASS()
class AWalkerPlayer : public ACharacter, public IIWalkerPlayer
{
    GENERATED_BODY()

// Async Events
public:
    FHandleCollectableEventSignature OnHandleCollectableEvent;

// Logic
public:
    AWalkerPlayer();

// Logic: Inputs binding
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

// Logic: Input Handling
private:
    virtual void CollectItem() override;
};
