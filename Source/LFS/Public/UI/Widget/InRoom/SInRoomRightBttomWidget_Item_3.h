// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SInRoomRightBttomWidget_Item_3 : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInRoomRightBttomWidget_Item_3)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SUniformGridPanel> Button_UniformGridPanel;
	
	TSharedPtr<class SScrollBox> List;

	//年月日按钮
	TSharedPtr<class SButton> Button_Day;
	TSharedPtr<class SButton> Button_Month;
	TSharedPtr<class SButton> Button_Year;

	FReply Button_Day_OnClick();
	FReply Button_Month_OnClick();
	FReply Button_Year_OnClick();
};
