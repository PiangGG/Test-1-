// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SLFSProgressbar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLFSProgressbar)
	{}
	SLATE_ATTRIBUTE(FString,Name)
	SLATE_ATTRIBUTE(FString,Number)
	SLATE_ATTRIBUTE(float,percent)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SProgressBar>ProgressBar;
	FString Name=TEXT("感知设备");
	FString Number = TEXT("100%");
	float percent=1.0f;
};
