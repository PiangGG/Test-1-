// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SMain_Left_State_Widget.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SMainLeftWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainLeftWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	//状态三个
	TSharedPtr<SMain_Left_State_Widget> Yujing_State;
	TSharedPtr<SMain_Left_State_Widget> Yunwei_State;
	TSharedPtr<SMain_Left_State_Widget> Gongdian_State;

	//统计图
	TSharedPtr<class SLineChartWidget> LineChartWidget;
};
