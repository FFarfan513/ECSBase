#pragma once

#include "CoreMinimal.h"
#include "BinaryDataHolder.generated.h"

USTRUCT()
struct ECSBASE_API FBinaryDataHolder {
	GENERATED_BODY()

	FBinaryDataHolder() = default;

	FBinaryDataHolder(TArray<uint8> binaryData);

	TArray<uint8> data;
};