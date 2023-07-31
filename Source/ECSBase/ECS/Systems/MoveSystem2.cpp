// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveSystem2.h"
#include <ECSBase/ECS/Components/MoveComponent.h>

MoveSystem2::MoveSystem2()
{
	UE_LOG(LogTemp, Warning, TEXT("MoveSystem2 create"));
	Filter.Add(UMoveComponent::StaticClass());
}

MoveSystem2::~MoveSystem2()
{
	UE_LOG(LogTemp, Warning, TEXT("MoveSystem2 delete"));
}

void MoveSystem2::Update(float DeltaTime)
{
	for (auto& pair : Entities)
	{
		auto entity = pair.Value;
		UMoveComponent* moveComp = entity->GetECSComponent<UMoveComponent>();

		FVector heading = moveComp->Direction * moveComp->Speed * DeltaTime;
		entity->SetActorLocation(moveComp->CurrentLocation + heading);
		//TODO rotation too?

		moveComp->CurrentLocation = entity->GetActorLocation();
	}
}