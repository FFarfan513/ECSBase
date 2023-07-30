// Fill out your copyright notice in the Description page of Project

#include "BaseEntity.h"
#include <ECSBase/ECS/ECSWorldGameInstance.h>

ABaseEntity::ABaseEntity()
{
	PrimaryActorTick.bCanEverTick = false;

	//ID = GetPathName();
}

const TSet<TSubclassOf<UBaseComponent>>& ABaseEntity::GetFilter()
{
	return Filter;
}

void ABaseEntity::BeginPlay()
{
	Super::BeginPlay();
	auto world = GETECSWORLD();
	if (world.IsValid())
	{
		SetFilterTypes();
		world->AddEntity(this);
		UE_LOG(LogTemp, Warning, TEXT("entity beginplay"));
		//// if gameinstance has saved data:
		//for (auto& component : ECSComponents)
		//{
		//	// populate saved data for each component
		//}
	}
}

void ABaseEntity::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//UE_LOG(LogTemp, Warning, TEXT("EndPlay for Entity %s"), *ID);
	auto world = GETECSWORLD();
	if (world.IsValid())
	{
		world->RemoveEntity(ID);
	}
	Filter.Empty();
}

void ABaseEntity::SetFilterTypes()
{
	auto& unrealComponents = GetComponents();
	for (auto& unrealComponent : unrealComponents)
	{
		if (unrealComponent->IsA(UBaseComponent::StaticClass()))
		{
			Filter.Add(unrealComponent->GetClass());
			//ECSComponents.Add(Cast<UBaseComponent>(unrealComponent));

			// or maybe check save data here to avoid needing to store the ecs components in a separate collection?
			// hmmmmm
		}
	}
}
