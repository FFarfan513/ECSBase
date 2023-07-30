// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Systems/BaseSystem.h"
#include "Entities/BaseEntity.h"
#include "ECSWorld.generated.h"

UCLASS()
class ECSBASE_API AECSWorld : public AActor
{
	GENERATED_BODY()
	
public:
	AECSWorld();

	TWeakObjectPtr<ABaseEntity> GetEntity(FString id);

	void AddEntity(TObjectPtr<ABaseEntity> entity);

	void RemoveEntity(FString id);

protected:
	UPROPERTY()
	TArray<TObjectPtr<UBaseSystem>> ECSSystems;

	UPROPERTY()
	TMap<FString, TObjectPtr<ABaseEntity>> ECSEntities;

	virtual void BeginPlay() override;

	virtual void FinishDestroy() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	void SetUpSystems();

	bool SystemShouldContainEntity(TObjectPtr<UBaseSystem> system, TObjectPtr<ABaseEntity> entity);
};
