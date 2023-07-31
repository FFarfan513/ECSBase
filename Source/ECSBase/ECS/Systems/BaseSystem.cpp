// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSystem.h"

BaseSystem::~BaseSystem()
{
	Filter.Empty();
}

const TSet<TSubclassOf<UBaseComponent>>& BaseSystem::GetFilter()
{
	return Filter;
}
