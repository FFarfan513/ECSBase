// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformSystem.h"
#include <ECSBase/ECS/Components/MovingPlatformComponent.h>
#include <ECSBase/ECS/Components/MoveComponent.h>
#include <ECSBase/ECS/Components/TimerComponent.h>

MovingPlatformSystem::MovingPlatformSystem()
{
	Filter.Add(UMovingPlatformComponent::StaticClass());
	Filter.Add(UMoveComponent::StaticClass());
	Filter.Add(UTimerComponent::StaticClass());
}

void MovingPlatformSystem::Update(float DeltaTime)
{
	for (const auto& [id, entity] : Entities)
	{
		auto timerComponent = entity->GetECSComponent<UTimerComponent>();
		auto moveComponent = entity->GetECSComponent<UMoveComponent>();

		if (!timerComponent->TimerActive)
		{
			moveComponent->Direction *= -1;
			
			timerComponent->TimerActive = true;
		}
	}
}