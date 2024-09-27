#include "TheWalkerGame/Public/Entities/Collectables/Collectable.h"

#include "TheWalkerGame/Public/Defaults.h"
#include "TheWalkerGame/Public/Utils.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"


ACollectable::ACollectable()
{
	// Glass of Alcohol by default
	if (Name.IsEmpty())
	{
		Name = Defaults::Collectables::Name;
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Set default name %s"), *Name);
	}

	bIsPicked = false;

	if (!bInitOnRT)
	{
		CreateStaticMeshComponent();
		CreateColliderBoxComponent();
	}
}

const FString ACollectable::GetItemName() const
{
	return Name;
}

void ACollectable::ToggleVisibility()
{
	StaticMeshComponent->ToggleVisibility();
}

void ACollectable::Pick()
{
	bIsPicked = true;
	SetActorLocation(Defaults::Collectables::NewPlace::Locations[Name]);
	StaticMeshComponent->SetRelativeRotation(Defaults::Collectables::NewPlace::Rotators[Name]);
	// UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Desired Rotation: %s"), *Defaults::Collectables::NewPlace::Rotations[Name].ToString());
	// UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Actual Rotation: %s"), *StaticMeshComponent->GetRelativeRotation().ToString());
}

void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	//
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Collectable1 BeginPlay! %s"), *Name);
	
	if (bInitOnRT)
	{
		CreateStaticMeshComponentRT();
		CreateColliderBoxComponentRT();
	}
}

void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACollectable::CreateStaticMeshComponent()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	// TODO: for now this is disabled
	//
	// UStaticMesh* StaticMesh = Utils::LoadStaticMesh(Defaults::Collectables::MeshPath[Name]);
	// if (StaticMesh)
	// {
	// 	StaticMeshComponent->SetStaticMesh(StaticMesh);
	// }
}

void ACollectable::CreateColliderBoxComponent()
{
	ColliderBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider Box Component"));
	ColliderBoxComponent->SetupAttachment(StaticMeshComponent);
}

void ACollectable::CreateStaticMeshComponentRT()
{
	StaticMeshComponent = Utils::CreateDynamicComponent<UStaticMeshComponent>(*Cast<AActor>(this), TEXT("Static Mesh Component"));

	UStaticMesh* StaticMesh = Utils::LoadStaticMeshOnRT(Defaults::Collectables::MeshPath[Name]);
	
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
