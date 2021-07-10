// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SDLGZWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDLGZWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	//进度条三个
	TSharedPtr<class SLFSProgressbar>Progressbar_A;
	TSharedPtr<class SLFSProgressbar>Progressbar_B;
	TSharedPtr<class SLFSProgressbar>Progressbar_C;

	//温度统一网格面板
	TSharedPtr<class SUniformGridPanel>WD_GridPanel;

	//电缆温度进度条
	TSharedPtr<class SHuanWidget> DL_1;
	TSharedPtr<class SHuanWidget> DL_2;
	TSharedPtr<class SHuanWidget> DL_3;
	TSharedPtr<class SHuanWidget> DL_4;
	TSharedPtr<class SHuanWidget> DL_5;
	TSharedPtr<class SHuanWidget> DL_6;
};
