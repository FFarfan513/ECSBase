// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseSystem.h"

void BaseSystem::AddEntity(TObjectPtr<ABaseEntity> entity)
{
	FString entityID = entity->GetEntityID();
	if (Entities.Contains(entityID))
	{
		UE_LOG(LogTemp, Error, TEXT("Attempting to add entity to System with duplicate ID '%s'"), *entityID);
		return;
	}
	Entities.Add(entityID, entity);
}

int32 BaseSystem::RemoveEntity(FString id)
{
	return Entities.Remove(id);
}

BaseSystem::~BaseSystem()
{
	Filter.Empty();
}