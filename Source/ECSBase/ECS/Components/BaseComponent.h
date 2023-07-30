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

	//virtual SomeStruct Save() = 0;
};