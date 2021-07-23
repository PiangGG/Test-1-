// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SInRoomLeftButtomWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInRoomLeftButtomWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	//底部标签栏按钮
	TSharedPtr<class SButton> HJJC_Button;
	TSharedPtr<class SButton> GJXX_Button;
	TSharedPtr<class SButton> ZNXJ_Button;
	TSharedPtr<class SButton> ZYGK_Button;

	TSharedPtr<class SOverlay>Content;
	TSharedPtr<class SInRoomRightBttomWidget_Item_1>InRoomRightBttomWidget_Item_1;
	TSharedPtr<class SInRoomRightBttomWidget_Item_2>InRoomRightBttomWidget_Item_2;
	TSharedPtr<class SInRoomRightBttomWidget_Item_3>InRoomRightBttomWidget_Item_3;
	TSharedPtr<class SInRoomRightBttomWidget_Item_4>InRoomRightBttomWidget_Item_4;
	public:
	FReply BuuttonOnClick_1();
	FReply BuuttonOnClick_2();
	FReply BuuttonOnClick_3();
	FReply BuuttonOnClick_4();

	void ShowHJJCWidegt();
	void HideHJJCWidget();

	TArray<AActor*> ArrayActors;
};
