// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveComponent.h"

void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("move comp beginplay"));
	CurrentLocation = GetOwner()->GetActorLocation();
}