// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ECSWorld.h"
#include "ECSWorldGameInstance.generated.h"

#define GETECSWORLD() GetWorld()->GetGameInstance<UECSWorldGameInstance>()->GetECSWorld()

UCLASS()
class ECSBASE_API UECSWorldGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "ECSWorld")
	TSubclassOf<AECSWorld> ECSWorldBlueprintClassType;

	const TWeakObjectPtr<AECSWorld> GetECSWorld();

	virtual void Init() override;

	virtual void Shutdown() override;

protected:
	UPROPERTY()
	TObjectPtr<AECSWorld> ECSWorld;
};
