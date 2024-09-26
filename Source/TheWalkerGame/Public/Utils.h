#pragma once

#include "CoreMinimal.h"

#if WITH_EDITOR
#include "LevelEditor.h"
#endif

namespace Utils
{
	UStaticMesh* LoadStaticMesh(const FString& PathToMesh)
	{
		if (PathToMesh.IsEmpty())
		{
			UE_LOG(LogTemp, Error, TEXT("Utils: Cannot load static mesh. The path is empty"));
			return nullptr;
		}
		static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshFinder(*PathToMesh);

		if (MeshFinder.Succeeded())
		{
			return MeshFinder.Object;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Utils: Failed to load mesh: %s"), *PathToMesh);
			return nullptr;
		}
	}

	UStaticMesh* LoadStaticMeshOnRT(const FString& PathToMesh)
	{
		return Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, *PathToMesh));
	}

	/**
	 * Creates new UActorComponent
	 * Attaches it to a component inside AActor
	 */
	template <typename T>
	static inline T* CreateDynamicComponent(AActor& Owner, const FName& ComponentName = FName(TEXT("DefaultComponentName")))
	{
		T* Component = NewObject<T>(&Owner, ComponentName);

		Owner.AddInstanceComponent(Component);
		// Component->SetupAttachment(Owner->Scene); //Or your component of choice (I usually make my own scene compnents)
		Owner.AddOwnedComponent(Component);
		Component->RegisterComponent();

	#if WITH_EDITOR
		if(Owner.IsSelectedInEditor())
		{
			FLevelEditorModule& LevelEditor = FModuleManager::LoadModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));
			TArray<UObject*> List;
			List.Add(&Owner);

			LevelEditor.BroadcastActorSelectionChanged(List, true);
		}
	#endif
	
		return Component;
	}
}