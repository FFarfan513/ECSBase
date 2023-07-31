// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Systems/BaseSystem2.h"
#include "ECSWorldGameInstanceSubsystem.generated.h"

#define GETECSWORLD2() GetWorld()->GetGameInstance()->GetSubsystem<UECSWorldGameInstanceSubsystem>()

UCLASS()
class ECSBASE_API UECSWorldGameInstanceSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
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
	TArray<TUniquePtr<BaseSystem2>> ECSSystems;

	UPROPERTY()
	TMap<FString, TObjectPtr<ABaseEntity>> ECSEntities;

private:
	bool initialized = false;

	bool SystemShouldContainEntity(const TUniquePtr<BaseSystem2>& system, const TObjectPtr<ABaseEntity>& entity);
};
