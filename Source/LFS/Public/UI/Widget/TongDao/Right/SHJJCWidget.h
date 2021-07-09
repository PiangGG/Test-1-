// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SHJJCWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHJJCWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SHuanWidget> HuanWidget_Wendu;
	TSharedPtr<class SHuanWidget> HuanWidget_ShuiWei;
	TSharedPtr<class SHuanWidget> HuanWidget_Yangan;
};
