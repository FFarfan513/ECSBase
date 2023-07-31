// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Systems/BaseSystem.h"
#include "ECSWorld.generated.h"

#define GETECSWORLD() GetWorld()->GetGameInstance()->GetSubsystem<UECSWorld>()

UCLASS()
class ECSBASE_API UECSWorld : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()
	
public:
	TWeakObjectPtr<ABaseEntity> GetEntity(FString id);
	void AddEntity(TObjectPtr<ABaseEntity> entity);
	void RemoveEntity(FString id);

	void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual void FinishDestroy() override;

	virtual void Tick(float DeltaTime) override;

	virtual TStatId GetStatId() const override { return TStatId(); }
	virtual UWorld* GetTickableGameObjectWorld() const override { return GetWorld(); }
	virtual bool IsTickable() const { return initialized; }
	virtual bool IsAllowedToTick() const { return initialized; }

protected:
	TArray<TUniquePtr<BaseSystem>> ECSSystems;

	UPROPERTY()
	TMap<FString, TObjectPtr<ABaseEntity>> ECSEntities;

private:
	bool initialized = false;

	bool SystemShouldContainEntity(const TUniquePtr<BaseSystem>& system, const TObjectPtr<ABaseEntity>& entity);
};
