// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"

void UHealthComponent::ReadWriteBinary(FArchive& archive)
{
	archive << this->Health;
}