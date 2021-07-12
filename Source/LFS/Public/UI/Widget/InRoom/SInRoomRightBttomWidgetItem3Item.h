// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SInRoomRightBttomWidgetItem3Item : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInRoomRightBttomWidgetItem3Item)
	{}
	SLATE_ATTRIBUTE(FString,Time)
	SLATE_ATTRIBUTE(FString,Content)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;
	FString Time;
	FString Content;
	TSharedPtr<class SButton> Item_Button;

	FReply Item_Button_OnClick();
};
