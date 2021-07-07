// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SLineChartWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLineChartWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SUniformGridPanel>  DMY_GridPanel;

	//年月日按钮
	TSharedPtr<class SButton> Button_Day;
	TSharedPtr<class SButton> Button_Month;
	TSharedPtr<class SButton> Button_Year;

	void ButtonOnclick();
};
