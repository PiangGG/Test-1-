// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
UENUM()
enum InRoom_UI_enum
{
	ShowTopAndLeftButtom,
	ShowAll,
};
class LFS_API SInRoomMainWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInRoomMainWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SMainTopWidget> MainTopWidget;

	TSharedPtr<class SInRoomLeftButtomWidget> InRoomLeftButtomWidget;
	
	TSharedPtr<class SInRoomLeftTopWidget> InRoomLeftTopWidget;

	TSharedPtr<class SInRoomLeftButtom_HJJCWidget> InRoomLeftButtom_HJJCWidget;
	void ShowHHJCWidget();
	void HideHJJCWidget();
	
	TSharedPtr<class SInRoomRightTopWidget> InRoomRightTopWidget;
	TSharedPtr<class SInRoomRightBttomWidget> InRoomRightBttomWidget;
};
