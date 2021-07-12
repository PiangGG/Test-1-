// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SInRoomRightButtomItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInRoomRightButtomItemWidget)
	{}
	SLATE_ATTRIBUTE(FString,Prop)
	SLATE_ATTRIBUTE(FString,Defect)
	SLATE_ATTRIBUTE(FString,Time)
	SLATE_ATTRIBUTE(FString,Handle)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	public:
	FString Prop;
	FString Defect;
	FString Time;
	FString Handle;
};
