// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BinaryDataHolder.generated.h"

USTRUCT()
struct ECSBASE_API FBinaryDataHolder
{
	GENERATED_BODY()

public:
	FBinaryDataHolder() = default;

	FBinaryDataHolder(TArray<uint8> binaryData);

	TArray<uint8> Data;
};