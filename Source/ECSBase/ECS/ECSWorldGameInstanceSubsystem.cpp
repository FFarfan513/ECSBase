// Fill out your copyright notice in the Description page of Project Settings.


#include "ECSWorldGameInstanceSubsystem.h"
#include "Systems/MoveSystem2.h"

TWeakObjectPtr<ABaseEntity> UECSWorldGameInstanceSubsystem::GetEntity(FString id)
{
	return ECSEntities.FindRef(id);
}

void UECSWorldGameInstanceSubsystem::AddEntity(TObjectPtr<ABaseEntity> entity)
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
			system->Entities.Add(entity->ID, entity);
		}
	}
}

void UECSWorldGameInstanceSubsystem::RemoveEntity(FString id)
{
	if (ECSEntities.Contains(id))
	{
		for (auto& system : ECSSystems)
		{
			system->Entities.Remove(id);
		}
		ECSEntities.Remove(id);
	}
}

void UECSWorldGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogTemp, Warning, TEXT("UECSWorldGameInstanceSubsystem initialize"));
	ECSSystems.Emplace(MakeUnique<MoveSystem2>());
	initialized = true;
}

void UECSWorldGameInstanceSubsystem::Deinitialize()
{
	initialized = false;
	UE_LOG(LogTemp, Warning, TEXT("UECSWorldGameInstanceSubsystem Deinitialize"));
}

void UECSWorldGameInstanceSubsystem::FinishDestroy()
{
	UE_LOG(LogTemp, Warning, TEXT("UECSWorldGameInstanceSubsystem FinishDestroy"));
	ECSEntities.Empty();
	ECSSystems.Empty();
	Super::FinishDestroy();
}

void UECSWorldGameInstanceSubsystem::Tick(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("UECSWorldGameInstanceSubsystem tick %d. whenpaused? %d. ineditor? %d"), GFrameCounter, IsTickableWhenPaused(), IsTickableInEditor());
	for (auto& system : ECSSystems)
	{
		system->Update(DeltaTime);
	}
}

bool UECSWorldGameInstanceSubsystem::SystemShouldContainEntity(const TUniquePtr<BaseSystem2>& system, const TObjectPtr<ABaseEntity>& entity)
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
