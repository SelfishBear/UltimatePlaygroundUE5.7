#pragma once

#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"
#include "Containers/Queue.h"

class FUP_AsyncWorker : public FRunnable
{
public:
	FUP_AsyncWorker(TQueue<int32, EQueueMode::Mpsc>* InResultQueue)
		: ResultQueue(InResultQueue)
	{}
	
	virtual bool Init() override
	{
		bRunning = true;
		return true;
	}
	
	virtual uint32 Run() override
	{
		while (bRunning)
		{
			int32 RandomValue = FMath::RandRange(0, 100);
			ResultQueue->Enqueue(RandomValue);
			
			FPlatformProcess::Sleep(1.0f);
		}
		return 0;
	}
	
	virtual void Stop() override
	{
		bRunning = false;
	}
	
private:
	TAtomic<bool> bRunning = false;
	TQueue<int32, EQueueMode::Mpsc>* ResultQueue = nullptr;
};
