// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UI/Widget/SLFSProgressbar.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SSBZXWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSBZXWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SLFSProgressbar> SLFSProgressbar_Ganzhi;
	TSharedPtr<class SLFSProgressbar> SLFSProgressbar_Shiping;
	TSharedPtr<class SLFSProgressbar> SLFSProgressbar_Zhaoming;
	TSharedPtr<class SLFSProgressbar> SLFSProgressbar_Xiaofang;
	TSharedPtr<class SLFSProgressbar> SLFSProgressbar_Other;
};
