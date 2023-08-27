// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSystem.h"

class ECSBASE_API TimerSystem : public BaseSystem
{
public:
	TimerSystem();

	void Update(float DeltaTime) override;
};