// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveComponent.h"

void UMoveComponent::BeginPlay()
{
	CurrentLocation = GetOwner()->GetActorLocation();
	Super::BeginPlay();
}

void UMoveComponent::ReadWriteBinary(FArchive& archive)
{
	archive << this->Speed;
	archive << this->Direction;
	archive << this->CurrentLocation;
}