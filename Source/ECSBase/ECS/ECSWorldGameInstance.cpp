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
	savedComponentData.Emplace(componentName, FBinaryDataHolder(binaryData));
}

TArray<uint8> UECSWorldGameInstance::LoadComponent(FString componentName)
{
	if (auto found = savedComponentData.Find(componentName))
	{
		return found->data;
	}
	return TArray<uint8>();
}
