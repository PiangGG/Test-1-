// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SLeft_Main : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLeft_Main)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	//下拉框
	TSharedPtr<STextComboBox>TextComboBox_floor;
	TArray<TSharedPtr<FString>> Array_floor;
	
	TSharedPtr<STextComboBox>TextComboBox_Location;
	TArray<TSharedPtr<FString>> Array_Location;

	//监控list
	TSharedPtr<class SScrollBox> JiankongList;
};
