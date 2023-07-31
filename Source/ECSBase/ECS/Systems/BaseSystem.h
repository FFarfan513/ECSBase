// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <ECSBase/ECS/Components/BaseComponent.h>
#include <ECSBase/ECS/Entities/BaseEntity.h>

class ECSBASE_API BaseSystem
{
public:
	void AddEntity(TObjectPtr<ABaseEntity> entity);

	void RemoveEntity(FString id);

	const TSet<TSubclassOf<UBaseComponent>>& GetFilter();

	virtual ~BaseSystem();

	virtual void Update(float DeltaTime) = 0;

protected:
	UPROPERTY()
	TMap<FString, TObjectPtr<ABaseEntity>> Entities;

	UPROPERTY()
	TSet<TSubclassOf<UBaseComponent>> Filter;
};
