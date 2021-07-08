// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SMJianKongItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMJianKongItemWidget)
	{}
	SLATE_ATTRIBUTE(FSlateBrush,ImageIcon)
	SLATE_ATTRIBUTE(FString,Name)
	SLATE_ATTRIBUTE(int32,Number)
	SLATE_ATTRIBUTE(FString,State)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	const struct FMainSlateStyle* MainStyle;

	FSlateBrush ImageIcon;

	FString Name = "开闭所";
	int32 Number = 0;
	FString State = "正常";
};
