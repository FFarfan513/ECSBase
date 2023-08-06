// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Systems/BaseSystem.h"

class ECSBASE_API ECSSystemLoader
{
public:
	static void LoadECSSystems(TArray<TUniquePtr<BaseSystem>>& systems);
};
