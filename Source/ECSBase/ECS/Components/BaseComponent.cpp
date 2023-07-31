// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseComponent.h"

UBaseComponent::UBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UBaseComponent::SaveComponentData() { }

void UBaseComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	SaveComponentData();
}
