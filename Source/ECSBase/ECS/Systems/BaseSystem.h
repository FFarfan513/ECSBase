// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <ECSBase/ECS/Components/BaseComponent.h>
#include <ECSBase/ECS/Entities/BaseEntity.h>

class ECSBASE_API BaseSystem
{
public:
	virtual ~BaseSystem();

	void AddEntity(const TObjectPtr<ABaseEntity>& entity);

	int32 RemoveEntity(const FString& id);

	FORCEINLINE const TSet<TSubclassOf<UBaseComponent>>& GetFilter() const { return Filter; }

	virtual void Update(float DeltaTime) = 0;

protected:
	UPROPERTY()
	TMap<FString, TObjectPtr<ABaseEntity>> Entities;

	UPROPERTY()
	TSet<TSubclassOf<UBaseComponent>> Filter;
};
