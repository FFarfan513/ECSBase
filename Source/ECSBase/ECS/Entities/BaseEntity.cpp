// Fill out your copyright notice in the Description page of Project

#include "BaseEntity.h"
#include <ECSBase/ECS/ECSWorld.h>

ABaseEntity::ABaseEntity()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseEntity::BeginPlay()
{
	Super::BeginPlay();

	SetFilterTypes();
	GETECSWORLD()->AddEntity(this);
}

void ABaseEntity::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GETECSWORLD()->RemoveEntity(ID);
	Components.Empty();
}

void ABaseEntity::SetFilterTypes()
{
	TInlineComponentArray<TObjectPtr<UBaseComponent>> ecsComponents;
	GetComponents(ecsComponents);

	Components.Reserve(ecsComponents.Num());
	for (const TObjectPtr<UBaseComponent>& component : ecsComponents)
	{
		Components.Emplace(component->GetClass(), component);
	}
}
