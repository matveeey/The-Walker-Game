#pragma once

#include "CoreMinimal.h"

namespace Defaults
{
	namespace Collectables
	{
		static const FString Name = "GlassOfAlcohol";

		const TMap<FString, FString> MeshPath =
		{
			{ TEXT("GlassOfAlcohol"), TEXT("StaticMesh'/Game/Assets/Items/glass_of_alcohol/glass_of_alcohol.glass_of_alcohol'") },
		};

		namespace NewPlace
		{
			// TODO: change to FTransform
			const TMap<FString, FVector> Locations =
			{
				{ TEXT("Bycicle"), FVector(30.0, 10.0, 360.0) },
				{ TEXT("EngagementRings"), FVector(476.0, 300.0, 429.0) },
				{ TEXT("GlassOfAlcohol"), FVector(60.0, 170.0, 440.0) },
				{ TEXT("LavenderBag"), FVector(370.0, 230.0, 430.0) },
				{ TEXT("MarxBookStack"), FVector(170.0, 200.0, 350.0) },
				{ TEXT("Pistol"), FVector(220.0, 350.0, 360.0) },
				{ TEXT("WorldMapBundle"), FVector(30.0, 260.0, 350.0) },
				{ TEXT("Door"), FVector(30.0, 260.0, 350.0) },
			};
			const TMap<FString, FRotator> Rotators =
			{
				{ TEXT("Bycicle"), FRotator(0.0, 16.0, 0.0) },
				{ TEXT("EngagementRings"), FRotator(0.0, 0.0, 0.0) },
				{ TEXT("GlassOfAlcohol"), FRotator(0.0, 0.0, 0.0) },
				{ TEXT("LavenderBag"), FRotator(0.0, 0.0, 77.0) },
				{ TEXT("MarxBookStack"), FRotator(0.0, 0.0, 0.0) },
				{ TEXT("Pistol"), FRotator(0.0, 60.0, 90.0) },
				{ TEXT("WorldMapBundle"), FRotator(0.0, 45.0, 0.0) },
				{ TEXT("Door"), FRotator(30.0, 260.0, 350.0) },
			};
		}
	}
}
