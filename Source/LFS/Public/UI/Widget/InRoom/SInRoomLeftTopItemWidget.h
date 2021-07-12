// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SInRoomLeftTopItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInRoomLeftTopItemWidget)
	{}
	SLATE_ATTRIBUTE(FString,name)
	SLATE_ATTRIBUTE(FString,level)
	SLATE_ATTRIBUTE(FString,Type)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	public:
	FString name;
	FString level;
	FString Type;
};
