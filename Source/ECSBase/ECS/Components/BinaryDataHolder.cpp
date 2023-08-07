// Fill out your copyright notice in the Description page of Project Settings.

#include "BinaryDataHolder.h"

FBinaryDataHolder::FBinaryDataHolder(TArray<uint8> binaryData)
{
	Data = binaryData;
}

FBinaryDataHolder::~FBinaryDataHolder()
{
	Data.Empty();
}
