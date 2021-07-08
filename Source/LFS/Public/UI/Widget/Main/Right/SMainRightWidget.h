// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SMainRightWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainRightWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SMainRight_Top>MainRight_Top;
	TSharedPtr<class SMainRight_Center>MainRight_Center;
	TSharedPtr<class SMainRight_Buttom>MainRight_Buttom;
};
