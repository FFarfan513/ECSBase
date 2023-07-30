// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSWorld.h"

AECSWorld::AECSWorld()
{
	PrimaryActorTick.bCanEverTick = true;
}

TWeakObjectPtr<ABaseEntity> AECSWorld::GetEntity(FString id)
{
	return ECSEntities.FindRef(id);
}

void AECSWorld::AddEntity(TObjectPtr<ABaseEntity> entity)
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

void AECSWorld::RemoveEntity(FString id)
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

void AECSWorld::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("ECSWorld BeginPlay"));
	SetUpSystems();
}

void AECSWorld::FinishDestroy()
{
	UE_LOG(LogTemp, Warning, TEXT("ECSWorld FinishDestroy"));
	ECSEntities.Empty();
	ECSSystems.Empty();
	Super::FinishDestroy();
}

void AECSWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//...
}

void AECSWorld::SetUpSystems()
{
	auto& unrealComponents = GetComponents();
	for (auto& unrealComponent : unrealComponents)
	{
		if (unrealComponent->IsA<UBaseSystem>())
		{
			ECSSystems.Add(Cast<UBaseSystem>(unrealComponent));
		}
	}
}

bool AECSWorld::SystemShouldContainEntity(TObjectPtr<UBaseSystem> system, TObjectPtr<ABaseEntity> entity)
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
