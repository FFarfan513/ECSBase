// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECSBASE_API UHealthComponent : public UBaseComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	int Health;

	virtual void ReadWriteBinary(FArchive& archive) override;
};
