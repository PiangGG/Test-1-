// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class LFS_API LFSDataHandle
{
	
public:
	
	LFSDataHandle();
	
	static void Initialize();
	
	static TSharedPtr<LFSDataHandle> Get();

	//初始化主页数据
	void InItMainMenuData();
private:
	static TSharedPtr<LFSDataHandle> Create();
private:
	static TSharedPtr<LFSDataHandle> DataInstance;

	//获取MenuStyle
	const struct FSlAiMenuStyle *MenuStyle;

public:
	//主页面状态数据
	TArray<TMap<FString,FString>> State;
};
