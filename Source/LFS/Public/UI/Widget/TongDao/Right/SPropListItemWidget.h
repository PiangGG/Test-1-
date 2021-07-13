// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SPropListItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPropListItemWidget)
	{}
	SLATE_ATTRIBUTE(FString,PropName)
	SLATE_ATTRIBUTE(FString,PropState)
	SLATE_ATTRIBUTE(FString,Time)
	SLATE_ATTRIBUTE(FString,PropHandle)
	SLATE_ATTRIBUTE(bool,bHandle)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;
	
	FString PropName=TEXT("设备名字");
	FString PropState=TEXT("状态");
	FString Time=TEXT("警告时间");
	FString PropHandle=TEXT("未处理");
	bool bHandle=false;
	
	FSlateFontInfo SlateFontInfo;
};
