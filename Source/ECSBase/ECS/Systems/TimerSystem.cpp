// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerSystem.h"
#include <ECSBase/ECS/Components/TimerComponent.h>

TimerSystem::TimerSystem()
{
	Filter.Add(UTimerComponent::StaticClass());
}

void TimerSystem::Update(float DeltaTime)
{
	for (const auto& [id, entity] : Entities)
	{
		auto timerComponent = entity->GetECSComponent<UTimerComponent>();

		if (timerComponent->TimerActive)
		{
			FTimerManager& timerManager = timerComponent->GetWorld()->GetTimerManager();
			FTimerHandle& handle = timerComponent->GetHandle();

			if (!timerManager.IsTimerActive(handle))
			{
				timerManager.SetTimer(handle, timerComponent->GetDelegate(), timerComponent->TimeRemaining, timerComponent->Looping);
			}

			timerComponent->TimeRemaining = timerManager.GetTimerRemaining(handle);
		}
	}
}