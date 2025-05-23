#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Interface/ICollectable.h"

#include "Collectable.generated.h"

UCLASS()
class ACollectable : public AActor, public IICollectable
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    bool bIsPicked;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UStaticMeshComponent* StaticMeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UBoxComponent* ColliderBoxComponent;

public:
    ACollectable();

// Components:
// 1. Box
// 2. Collider 2x times bigger than box
// 3. Static Mesh

public:
    virtual const FString GetItemName() const override;
    
    // 'const' here is kinda stupid because it actually changes the state of an instance..
    void ToggleVisibility();
    void Pick();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    void CreateStaticMeshComponent();
    void CreateColliderBoxComponent();
    void CreateStaticMeshComponentRT();
    void CreateColliderBoxComponentRT();

    bool bInitOnRT = false;
};
