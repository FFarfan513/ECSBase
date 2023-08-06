// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Components/BinaryDataHolder.h"
#include "ECSWorldGameInstance.generated.h"

#define GETECSGAMEINSTANCE() GetWorld()->GetGameInstance<UECSWorldGameInstance>()

UCLASS()
class ECSBASE_API UECSWorldGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	virtual void Shutdown() override;

	void SaveComponent(FString componentName, TArray<uint8> binaryData);

	TArray<uint8> LoadComponent(FString componentName);

protected:
	// Save this map to file when game saves. When game loads, populate this map from file
	UPROPERTY(SaveGame)
	TMap<FString, FBinaryDataHolder> savedComponentData;
};
