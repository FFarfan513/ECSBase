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

	FORCEINLINE const FString& GetEntityID() const { return ID; }

	FORCEINLINE bool ContainsComponentType(TSubclassOf<UBaseComponent> type) const { return Components.Contains(type); }

	template<class T> TObjectPtr<T> GetECSComponent() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, const UBaseComponent>::Value, "'T' template parameter to GetECSComponent must be derived from UBaseComponent");
		return (T*)Components.FindRef(T::StaticClass());
	}

protected:
	UPROPERTY(EditAnywhere)
	FString ID;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY()
	TMap<TSubclassOf<UBaseComponent>, TObjectPtr<UBaseComponent>> Components;

	void SetFilterTypes();
};
