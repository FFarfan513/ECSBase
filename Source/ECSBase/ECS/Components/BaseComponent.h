// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ECSBASE_API UBaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBaseComponent();

	//Get values of variables, put them into some kind of struct, then save them to the GameInstance.
	virtual void SaveComponentData();

	//virtual void LoadComponentData() = 0;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};