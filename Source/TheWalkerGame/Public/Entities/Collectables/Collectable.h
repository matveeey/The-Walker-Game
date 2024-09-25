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
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    FString Name;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    bool bIsPicked = false;
    
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

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    void CreateStaticMeshComponentRT();
    void CreateColliderBoxComponentRT();

};
