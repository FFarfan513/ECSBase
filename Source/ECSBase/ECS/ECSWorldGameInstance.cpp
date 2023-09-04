// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSWorldGameInstance.h"

void UECSWorldGameInstance::Init()
{
	Super::Init();
}

void UECSWorldGameInstance::Shutdown()
{
	Super::Shutdown();
}

void UECSWorldGameInstance::SaveComponent(const FString& componentName, const TArray<uint8>& binaryData)
{
	if (!componentName.IsEmpty())
	{
		savedComponentData.Emplace(componentName, FBinaryDataHolder(binaryData));
	}
}

const TArray<uint8>* UECSWorldGameInstance::LoadComponent(const FString& componentName) const
{
	if (!componentName.IsEmpty())
	{
		if (const FBinaryDataHolder* found = savedComponentData.Find(componentName))
		{
			return found->GetBinaryData();
		}
	}
	return nullptr;
}