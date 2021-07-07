// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SMainWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	private:
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;
	//左邊模塊
	TSharedPtr<class SMainLeftWidget> MainLeftWidget;
	TSharedPtr<class SMainTopWidget> MainTopWidget;
	TSharedPtr<class SMainRightWidget> MainRightWidget;
	TSharedPtr<class SMainBottomWidget> MainBottomWidget;
	TSharedPtr<class SMainCenterWidget> MainCenterWidget;

	//DPI缩放
	TAttribute<float> UIScaler;
};
