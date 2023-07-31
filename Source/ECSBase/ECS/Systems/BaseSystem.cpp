// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseSystem.h"

void BaseSystem::AddEntity(TObjectPtr<ABaseEntity> entity)
{
	if (Entities.Contains(entity->ID))
	{
		UE_LOG(LogTemp, Error, TEXT("Attempting to add entity to System with duplicate ID '%s'"), *entity->ID);
		return;
	}
	Entities.Add(entity->ID, entity);
}

void BaseSystem::RemoveEntity(FString id)
{
	Entities.Remove(id);
}

const TSet<TSubclassOf<UBaseComponent>>& BaseSystem::GetFilter()
{
	return Filter;
}

BaseSystem::~BaseSystem()
{
	Filter.Empty();
}