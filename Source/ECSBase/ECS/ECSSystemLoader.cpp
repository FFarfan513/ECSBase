// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSSystemLoader.h"
#include "Systems/MoveSystem.h"
#include "Systems/TimerSystem.h"
#include "Systems/MovingPlatformSystem.h"
// Add more here when adding new ECS Systems

void ECSSystemLoader::LoadECSSystems(TArray<TUniquePtr<BaseSystem>>& systems)
{
	systems.Emplace(MakeUnique<MoveSystem>());
	systems.Emplace(MakeUnique<TimerSystem>());
	systems.Emplace(MakeUnique<MovingPlatformSystem>());
	// Add more here when adding new ECS Systems
}
