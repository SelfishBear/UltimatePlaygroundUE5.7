// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UP_AsyncActor.generated.h"

UCLASS()
class ULTIMATEPLAYGROUND_API AUP_AsyncActor : public AActor
{
	GENERATED_BODY()

public:
	AUP_AsyncActor();
	
	UFUNCTION(BlueprintCallable, Category = "Async Tasks")
	void StartAsyncTaskSleep();
	
	UFUNCTION(BlueprintCallable, Category = "Async Tasks")
	void StartHeavyComputationAsyncTask();
};
