// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSSystemLoader.h"
#include "Systems/MoveSystem.h"
// Add more here when adding new ECS Systems

void ECSSystemLoader::LoadECSSystems(TArray<TUniquePtr<BaseSystem>>& systems)
{
	systems.Emplace(MakeUnique<MoveSystem>());
	// Add more here when adding new ECS Systems
}
