// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SInRoomRightTopItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInRoomRightTopItemWidget)
	{}
	SLATE_ATTRIBUTE(FString,Name)
	SLATE_ATTRIBUTE(FString,Type)
	SLATE_ATTRIBUTE(FString,State)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	public:
	FString Name;
	FString Type;
	FString State;
};
