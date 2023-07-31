// Fill out your copyright notice in the Description page of Project

#include "BaseEntity.h"
#include <ECSBase/ECS/ECSWorld.h>

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

	SetFilterTypes();
	GETECSWORLD()->AddEntity(this);
	//UE_LOG(LogTemp, Warning, TEXT("BeginPlay for Entity %s"), *ID);
}

void ABaseEntity::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//UE_LOG(LogTemp, Warning, TEXT("EndPlay for Entity %s"), *ID);
	GETECSWORLD()->RemoveEntity(ID);
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

			// if gameinstance has saved data:
			//auto base = Cast<UBaseComponent>(unrealComponent);
			//base->LoadComponentData();
		}
	}
}
