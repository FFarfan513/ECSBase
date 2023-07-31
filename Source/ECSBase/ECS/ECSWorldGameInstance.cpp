// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSWorldGameInstance.h"

void UECSWorldGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("GameInstance initialize"));
}

void UECSWorldGameInstance::Shutdown()
{
	Super::Shutdown();
}