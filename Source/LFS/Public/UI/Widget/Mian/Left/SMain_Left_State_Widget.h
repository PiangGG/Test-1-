// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SMain_Left_State_Widget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMain_Left_State_Widget)
	{}
		SLATE_ATTRIBUTE(FSlateBrush,StateImageIcon)
		SLATE_ATTRIBUTE(FString,ShowText)
		SLATE_ATTRIBUTE(FString,ProgressBarText)
		SLATE_ATTRIBUTE(float,ProbarSize)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	/*
	 * 属性
	 */
	//显示图标
	FSlateBrush StateImageIcon;
	//显示字体
	FString ShowText;
	//进度条里面字体
	FString ProgressBarText;
	//进度条比列
	float ProbarSize;
	
	public:
	TSharedPtr<class SProgressBar> ProgressBar;

	
};
