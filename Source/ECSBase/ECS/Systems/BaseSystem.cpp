// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseSystem.h"

UBaseSystem::UBaseSystem()
{
	//TickGroup setting?
}

const TSet<TSubclassOf<UBaseComponent>>& UBaseSystem::GetFilter()
{
	return Filter;
}

void UBaseSystem::BeginPlay()
{
	Super::BeginPlay();
}

void UBaseSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
