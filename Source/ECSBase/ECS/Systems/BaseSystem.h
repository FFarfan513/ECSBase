// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <ECSBase/ECS/Components/BaseComponent.h>
#include <ECSBase/ECS/Entities/BaseEntity.h>
#include "BaseSystem.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ECSBASE_API UBaseSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, TObjectPtr<ABaseEntity>> Entities;

	UBaseSystem();

	const TSet<TSubclassOf<UBaseComponent>>& GetFilter();

protected:
	UPROPERTY()
	TSet<TSubclassOf<UBaseComponent>> Filter;

	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};