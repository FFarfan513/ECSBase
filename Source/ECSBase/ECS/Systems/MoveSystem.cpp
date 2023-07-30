// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveSystem.h"
#include <ECSBase/ECS/Components/MoveComponent.h>

UMoveSystem::UMoveSystem()
{
	PrimaryComponentTick.bCanEverTick = true;

	Filter.Add(UMoveComponent::StaticClass());
}

void UMoveSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (auto& pair : Entities)
	{
		auto entity = pair.Value;
		UMoveComponent* moveComp = entity->GetECSComponent<UMoveComponent>();

		FVector heading = moveComp->Direction * moveComp->Speed * DeltaTime;
		entity->SetActorLocation(moveComp->CurrentLocation + heading);
		//TODO rotation too?

		moveComp->CurrentLocation = entity->GetActorLocation();
	}
}

