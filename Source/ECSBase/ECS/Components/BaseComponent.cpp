// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseComponent.h"
#include <ECSBase/ECS/Entities/BaseEntity.h>
#include <ECSBase/ECS/ECSWorldGameInstance.h>

UBaseComponent::UBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UBaseComponent::ReadWriteBinary(FArchive& archive) { }

void UBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	if (const ABaseEntity* entity = Cast<ABaseEntity>(GetOwner()))
	{
		const FString& entityID = entity->GetEntityID();
		if (!entityID.IsEmpty())
		{
			ComponentID = entityID + "|" + GetClass()->GetName();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Entity actor %s has blank Entity ID"), *entity->GetFullName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Actor '%s' is not of type BaseEntity"), *GetOwner()->GetFullName());
	}

	if (const TArray<uint8>* componentData = GETECSGAMEINSTANCE()->LoadComponent(ComponentID))
	{
		FMemoryReader reader(*componentData);
		ReadWriteBinary(reader);
	}
}

void UBaseComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	TArray<uint8> componentData;
	FMemoryWriter writer(componentData);
	ReadWriteBinary(writer);
	GETECSGAMEINSTANCE()->SaveComponent(ComponentID, componentData);
}