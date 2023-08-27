// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseComponent.h"
#include "TimerComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ECSBASE_API UTimerComponent : public UBaseComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool TimerActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimerDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float TimeRemaining;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Looping;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void ReadWriteBinary(FArchive& archive) override;

	FORCEINLINE const FTimerDelegate& GetDelegate() const { return timerDelegate; }

	FORCEINLINE FTimerHandle& GetHandle() { return timerComponentHandle; }

protected:
	FTimerHandle timerComponentHandle;

	FTimerDelegate timerDelegate;
};
