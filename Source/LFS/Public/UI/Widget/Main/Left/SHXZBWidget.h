// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SHXZBWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHXZBWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SUniformGridPanel> HXZB_GridPanel;

	TSharedPtr<class SHuanWidget> Huan_Zhonghe;
	TSharedPtr<class SHuanWidget> Huan_Guzhang;
	TSharedPtr<class SHuanWidget> Huan_Yunwei;
};
