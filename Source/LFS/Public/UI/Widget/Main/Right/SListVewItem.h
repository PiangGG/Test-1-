// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SListViewItem : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SListViewItem)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;
	FString name=TEXT("来福士1#开闭所");
	FString state=TEXT("正常");
	FString xiangqing=TEXT("运行状态正常");
};
