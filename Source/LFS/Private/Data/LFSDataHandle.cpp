// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/LFSDataHandle.h"

#include "Data/LFSJsonHandle.h"
#include "Data/LFSSingleton.h"

TSharedPtr<LFSDataHandle> LFSDataHandle::DataInstance=NULL;
LFSDataHandle::LFSDataHandle()
{
	InItMainMenuData();
}

void LFSDataHandle::Initialize()
{
	if (!DataInstance.IsValid())
	{
		DataInstance=LFSDataHandle::Create();
	}
}

TSharedPtr<LFSDataHandle> LFSDataHandle::Get()
{
	Initialize();
	return DataInstance;
}

void LFSDataHandle::InItMainMenuData()
{
	//初始化主页面状态数据
	LFSSingleton<LFSJsonHandle>::Get()->ConditionMonitoring(State);
}

TSharedPtr<LFSDataHandle> LFSDataHandle::Create()
{
	TSharedPtr<LFSDataHandle> DataRef = MakeShareable(new LFSDataHandle());
	return DataRef;
}