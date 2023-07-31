// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ECSWorldGameInstance.generated.h"

UCLASS()
class ECSBASE_API UECSWorldGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	//hold saved entity data somehow

	virtual void Init() override;

	virtual void Shutdown() override;
};
