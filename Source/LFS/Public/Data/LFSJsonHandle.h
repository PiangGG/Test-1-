// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class LFS_API LFSJsonHandle
{
public:
	LFSJsonHandle();
	
private:
	//读取Json文件到字符串
	bool LoadStringFromFile(const FString& FileName,const FString& RelaPath,FString& ResultString);

	//FJsonObject转换为Json格式字符串
	bool GetFStringInJsonData(const TSharedPtr<FJsonObject>& JsonObj,FString& JsonStr);

	//保存字符串到文件
	bool WriteFileWithJsonData(const FString& JsonStr,const FString& RelaPath,const FString& FileName);

public:
	//读取状态监测数据
	void ConditionMonitoring(TArray<TMap<FString,FString>>& ConditionMonitoringDataList);
private:
	//存档文件名
	FString MainMenuFileName;

	//数据文件相对位置
	FString RelativePath;
};
