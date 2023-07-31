// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSystem2.h"

class ECSBASE_API MoveSystem2 : public BaseSystem2
{
public:
	MoveSystem2();

	~MoveSystem2();

	virtual void Update(float DeltaTime) override;
};
