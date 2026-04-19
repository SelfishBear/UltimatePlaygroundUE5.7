// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Multithreading/UP_AsyncActor.h"

AUP_AsyncActor::AUP_AsyncActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AUP_AsyncActor::StartAsyncTaskSleep()
{
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, []()
	{
		FPlatformProcess::Sleep(2.0f);
		UE_LOG(LogTemp, Warning, TEXT("Async Task Completed!"));
	});
}

void AUP_AsyncActor::StartHeavyComputationAsyncTask()
{
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, []()
	{
		int32 Result = 0;
		for (int32 i = 0; i < 100000000; ++i)
		{
			Result += i;
		}
		
		FPlatformProcess::Sleep(2.0f);

		AsyncTask(ENamedThreads::GameThread, [Result]()
		{
			UE_LOG(LogTemp, Warning, TEXT("Heavy Computation Result: %d"), Result);
		});
	});
}
