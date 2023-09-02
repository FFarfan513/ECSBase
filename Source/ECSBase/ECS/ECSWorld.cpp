// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSWorld.h"
#include "ECSSystemLoader.h"

TWeakObjectPtr<ABaseEntity> UECSWorld::GetEntity(const FString& id) const
{
	return ECSEntities.FindRef(id);
}

void UECSWorld::AddEntity(const TObjectPtr<ABaseEntity>& entity)
{
	FString entityID = entity->GetEntityID();
	if (ECSEntities.Contains(entityID))
	{
		return;
	}

	ECSEntities.Add(entityID, entity);

	for (auto& system : ECSSystems)
	{
		if (SystemShouldContainEntity(system, entity))
		{
			system->AddEntity(entity);
		}
	}
}

void UECSWorld::RemoveEntity(const FString& id)
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
	Super::Initialize(Collection);
	ECSSystemLoader::LoadECSSystems(ECSSystems);
	initialized = true;
}

void UECSWorld::Deinitialize()
{
	Super::Deinitialize();
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

bool UECSWorld::SystemShouldContainEntity(const TUniquePtr<BaseSystem>& system, const TObjectPtr<ABaseEntity>& entity) const
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
