// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSystem2.h"

BaseSystem2::~BaseSystem2()
{
	Filter.Empty();
}

const TSet<TSubclassOf<UBaseComponent>>& BaseSystem2::GetFilter()
{
	return Filter;
}
