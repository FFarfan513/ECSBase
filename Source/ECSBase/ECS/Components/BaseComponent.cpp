// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseComponent.h"
#include <ECSBase/ECS/Entities/BaseEntity.h>
#include <ECSBase/ECS/ECSWorldGameInstance.h>

UBaseComponent::UBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FString UBaseComponent::GetID()
{
	if (auto entity = Cast<ABaseEntity>(GetOwner()))
	{
		return entity->ID + GetName();
	}

	return FString();
}

void UBaseComponent::ReadWriteBinary(FArchive& archive) { }

void UBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<uint8> componentData = GETECSGAMEINSTANCE()->LoadComponent(GetID());
	if (componentData.Num() > 0)
	{
		FMemoryReader reader(componentData);
		ReadWriteBinary(reader);
	}
}

void UBaseComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	TArray<uint8> componentData;
	FMemoryWriter writer(componentData);
	ReadWriteBinary(writer);
	GETECSGAMEINSTANCE()->SaveComponent(GetID(), componentData);
}