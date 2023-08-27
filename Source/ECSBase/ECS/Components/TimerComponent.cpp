// Fill out your copyright notice in the Description page of Project Settings.

#include "TimerComponent.h"

void UTimerComponent::BeginPlay()
{
	TimeRemaining = TimerDuration;
	Super::BeginPlay();

	timerDelegate.BindLambda([this] {
		if (!Looping)
		{
			TimerActive = false;
		}
		TimeRemaining = TimerDuration;
	});
}

void UTimerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(timerComponentHandle);
	timerDelegate.Unbind();
}

void UTimerComponent::ReadWriteBinary(FArchive& archive)
{
	archive << this->TimerActive;
	archive << this->TimerDuration;
	archive << this->TimeRemaining;
	archive << this->Looping;
}