// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveSystem.h"
#include <ECSBase/ECS/Components/MoveComponent.h>

MoveSystem::MoveSystem() : BaseSystem(UMoveComponent::StaticClass()) { }

void MoveSystem::Update(float DeltaTime)
{
	for (const auto& [id, entity] : Entities)
	{
		UMoveComponent* moveComp = entity->GetECSComponent<UMoveComponent>();

		FVector heading = moveComp->Direction * moveComp->Speed * DeltaTime;
		entity->SetActorLocation(moveComp->CurrentLocation + heading);
		//TODO rotation too?

		moveComp->CurrentLocation = entity->GetActorLocation();
	}
}