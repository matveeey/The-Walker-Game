#include "TheWalkerGame/Public/Entities/Collectables/Collectable.h"

#include "TheWalkerGame/Public/Defaults.h"
#include "TheWalkerGame/Public/Utils.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"


ACollectable::ACollectable()
{
	// Glass of Alcohol by default
	Name = Defaults::Collectables::Name;
}

const FString ACollectable::GetItemName() const
{
	return Name;
}

// 1) велосипед
// 2) карта мира (можно показать рулон свёрнутой бумаги
// 3) стакан с алкоголем
// 4) мешочек с лавандой
// 5) стопка книг по марксизму
// 6) обручальные кольца
// 7) пистолет

void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Collectable BeginPlay! %s"), *Name);
	
	Name = Defaults::Collectables::Name; // Glass of Alcohol

	CreateStaticMeshComponentRT();
	CreateColliderBoxComponentRT();
}

void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACollectable::CreateStaticMeshComponentRT()
{
	StaticMeshComponent = Utils::CreateDynamicComponent<UStaticMeshComponent>(*Cast<AActor>(this), TEXT("Static Mesh Component"));

	UStaticMesh* StaticMesh = Utils::LoadStaticMeshOnRT(Name);
	
	if (StaticMesh)
	{
		StaticMeshComponent->SetStaticMesh(StaticMesh);
	}

	StaticMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ACollectable::CreateColliderBoxComponentRT()
{
	ColliderBoxComponent = Utils::CreateDynamicComponent<UBoxComponent>(*Cast<AActor>(this), TEXT("Collider Box Component"));
	ColliderBoxComponent->AttachToComponent(StaticMeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
}
