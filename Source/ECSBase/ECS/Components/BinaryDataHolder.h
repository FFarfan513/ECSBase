#pragma once

#include "CoreMinimal.h"
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