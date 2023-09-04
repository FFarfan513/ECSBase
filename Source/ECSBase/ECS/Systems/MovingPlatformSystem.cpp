// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformSystem.h"
#include <ECSBase/ECS/Components/MovingPlatformComponent.h>
#include <ECSBase/ECS/Components/MoveComponent.h>
#include <ECSBase/ECS/Components/TimerComponent.h>

MovingPlatformSystem::MovingPlatformSystem()
{
	Filter.Reserve(3);
	Filter.Emplace(UMovingPlatformComponent::StaticClass());
	Filter.Emplace(UMoveComponent::StaticClass());
	Filter.Emplace(UTimerComponent::StaticClass());
}

void MovingPlatformSystem::Update(float DeltaTime)
{
	for (const auto& [id, entity] : Entities)
	{
		UTimerComponent* timerComponent = entity->GetECSComponent<UTimerComponent>();
		UMoveComponent* moveComponent = entity->GetECSComponent<UMoveComponent>();

		if (!timerComponent->TimerActive)
		{
			moveComponent->Direction *= -1;
			
			timerComponent->TimerActive = true;
		}
	}
}