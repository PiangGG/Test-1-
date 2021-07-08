// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SMainRight_Center : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainRight_Center)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;
	//列表
	TSharedPtr<class SScrollBox> listView;
};
