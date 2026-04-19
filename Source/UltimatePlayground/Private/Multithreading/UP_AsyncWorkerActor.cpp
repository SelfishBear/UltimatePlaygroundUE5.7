// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Multithreading/UP_AsyncWorkerActor.h"

#include "Public/Multithreading/FUP_AsyncWorker.h"


AUP_AsyncWorkerActor::AUP_AsyncWorkerActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AUP_AsyncWorkerActor::BeginPlay()
{
	Super::BeginPlay();

	AsyncWorker = MakeUnique<FUP_AsyncWorker>(&ResultQueue);

	WorkerThread = FRunnableThread::Create(AsyncWorker.Get(), TEXT("FUP_AsyncWorkerThread"), 0, TPri_BelowNormal);
}

void AUP_AsyncWorkerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	int32 Value;
	
	while (ResultQueue.Dequeue(Value))
	{
		UE_LOG(LogTemp, Log, TEXT("Received value from async worker: %d"), Value);
	}
}

void AUP_AsyncWorkerActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	if (AsyncWorker)
	{
		AsyncWorker->Stop();
	}
	
	if (WorkerThread)
	{
		WorkerThread->WaitForCompletion();
		delete WorkerThread;
		WorkerThread = nullptr;
	}
}
