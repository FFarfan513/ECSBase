// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSSystemLoader.h"
#include "Systems/MoveSystem.h"
#include "Systems/TimerSystem.h"
#include "Systems/MovingPlatformSystem.h"
// Add more here when adding new ECS Systems

void ECSSystemLoader::LoadECSSystems(TArray<TUniquePtr<BaseSystem>>& systems)
{
	// TODO: Find a cleaner way to set up all systems.
	// It's possible to have all systems act like FTickable GameInstanceSubsystems, but that
	// would prevent the ability to control the order they update in, and prevent the ability
	// to reserve the memory in the systems TArray beforehand. Note that this array is still
	// needed despite the systems loading on their own, to be able to call all systems'
	// AddEntity and RemoveEntity functions. Would it be worth the tradeoffs? Hmm...
	systems.Reserve(3);
	systems.Emplace(MakeUnique<MoveSystem>());
	systems.Emplace(MakeUnique<TimerSystem>());
	systems.Emplace(MakeUnique<MovingPlatformSystem>());
	// Add more here when adding new ECS Systems
}
