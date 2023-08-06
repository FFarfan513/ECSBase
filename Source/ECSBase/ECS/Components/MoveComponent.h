// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseComponent.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECSBASE_API UMoveComponent : public UBaseComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	FVector Direction;

	UPROPERTY(VisibleAnywhere)
	FVector CurrentLocation;

	virtual void BeginPlay() override;

	virtual void ReadWriteBinary(FArchive& archive) override;
};