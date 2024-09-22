#include "TheWalkerGame/Public/Entities/Collectables/Collectable.h"

#include "TheWalkerGame/Public/Defaults.h"

ACollectable::ACollectable()
{
}

const FString ACollectable::GetItemName() const
{
    return Defaults::Collectables::Name;
}

void ACollectable::BeginPlay()
{
    Super::BeginPlay();
}

void ACollectable::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}