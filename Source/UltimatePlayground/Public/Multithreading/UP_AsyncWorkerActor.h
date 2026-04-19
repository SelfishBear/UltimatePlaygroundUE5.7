// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FUP_AsyncWorker.h"
#include "GameFramework/Actor.h"
#include "UP_AsyncWorkerActor.generated.h"

UCLASS()
class ULTIMATEPLAYGROUND_API AUP_AsyncWorkerActor : public AActor
{
	GENERATED_BODY()

public:
	AUP_AsyncWorkerActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
private:
	TUniquePtr<FUP_AsyncWorker> AsyncWorker;
	FRunnableThread* WorkerThread = nullptr;
	
	TQueue<int32, EQueueMode::Mpsc> ResultQueue;
};
