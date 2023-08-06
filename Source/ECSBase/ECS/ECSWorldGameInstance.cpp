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

void UECSWorldGameInstance::SaveComponent(FString componentName, TArray<uint8> binaryData)
{
	if (!componentName.IsEmpty())
	{
		savedComponentData.Emplace(componentName, FBinaryDataHolder(binaryData));
	}
}

TArray<uint8> UECSWorldGameInstance::LoadComponent(FString componentName)
{
	if (!componentName.IsEmpty())
	{
		if (auto found = savedComponentData.Find(componentName))
		{
			return found->Data;
		}
	}
	return TArray<uint8>();
}
