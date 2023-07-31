// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveComponent.h"

void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentLocation = GetOwner()->GetActorLocation();
}