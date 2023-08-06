// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <ECSBase/ECS/Components/BaseComponent.h>
#include "BaseEntity.generated.h"

UCLASS()
class ECSBASE_API ABaseEntity : public AActor
{
	GENERATED_BODY()
	
public:
	ABaseEntity();

	const FString GetEntityID() const { return ID; }

	const TSet<TSubclassOf<UBaseComponent>>& GetFilter() const { return Filter; }

	template<class T> TObjectPtr<T> GetECSComponent() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, const UBaseComponent>::Value, "'T' template parameter to GetECSComponent must be derived from UBaseComponent");
		return FindComponentByClass<T>();
	}

protected:
	UPROPERTY(EditAnywhere)
	FString ID;

	UPROPERTY()
	TSet<TSubclassOf<UBaseComponent>> Filter;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void SetFilterTypes();
};
