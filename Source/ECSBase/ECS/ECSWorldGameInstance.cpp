// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSWorldGameInstance.h"

const TWeakObjectPtr<AECSWorld> UECSWorldGameInstance::GetECSWorld()
{
	return ECSWorld;
}

void UECSWorldGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("GameInstance initialize"));

	if (ECSWorldBlueprintClassType == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR! Blueprint type not found for ECSWorld!"));
		return;
	}

	// Spawn ECSWorld Actor
	ECSWorld = GetWorld()->SpawnActor<AECSWorld>(ECSWorldBlueprintClassType);
}

void UECSWorldGameInstance::Shutdown()
{
	Super::Shutdown();
	UE_LOG(LogTemp, Warning, TEXT("GameInstance shutdown"));
}