// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSWorld.h"
#include "Systems/MoveSystem.h"

TWeakObjectPtr<ABaseEntity> UECSWorld::GetEntity(FString id)
{
	return ECSEntities.FindRef(id);
}

void UECSWorld::AddEntity(TObjectPtr<ABaseEntity> entity)
{
	if (ECSEntities.Contains(entity->ID))
	{
		UE_LOG(LogTemp, Error, TEXT("Attempting to add entity with duplicate ID '%s'"), *entity->ID);
		return;
	}

	ECSEntities.Add(entity->ID, entity);

	for (auto& system : ECSSystems)
	{
		if (SystemShouldContainEntity(system, entity))
		{
			system->AddEntity(entity);
		}
	}
}

void UECSWorld::RemoveEntity(FString id)
{
	if (ECSEntities.Contains(id))
	{
		for (auto& system : ECSSystems)
		{
			system->RemoveEntity(id);
		}
		ECSEntities.Remove(id);
	}
}

void UECSWorld::Initialize(FSubsystemCollectionBase& Collection)
{
	ECSSystems.Emplace(MakeUnique<MoveSystem>());
	initialized = true;
}

void UECSWorld::Deinitialize()
{
	initialized = false;
}

void UECSWorld::FinishDestroy()
{
	ECSEntities.Empty();
	ECSSystems.Empty();
	Super::FinishDestroy();
}

void UECSWorld::Tick(float DeltaTime)
{
	for (auto& system : ECSSystems)
	{
		system->Update(DeltaTime);
	}
}

bool UECSWorld::SystemShouldContainEntity(const TUniquePtr<BaseSystem>& system, const TObjectPtr<ABaseEntity>& entity)
{
	auto& entityFilter = entity->GetFilter();
	auto& systemFilter = system->GetFilter();
	for (auto& systemType : systemFilter)
	{
		if (!entityFilter.Contains(systemType))
		{
			return false;
		}
	}

	return true;
}
