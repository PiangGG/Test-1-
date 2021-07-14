// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SActorObjectInfoMainWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SActorObjectInfoMainWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SOverlay>Overlay;
	//Button
	TSharedPtr<class SButton> Button_DLXX;
	TSharedPtr<class SButton> Button_TZXX;
	TSharedPtr<class SButton> Button_YXSJ;
	TSharedPtr<class SButton> Button_DLGZ;

	//容器面板
	TSharedPtr<class SOverlay> Content;
	//信息面板
	TSharedPtr<class SDLXXWidget> DLXXWidget;//电缆信息
	//TSharedPtr<class SDLXXWidget> DLXXWidget;//台账信息
	TSharedPtr<class SYXSJWidget> YXSJWidget;//运行数据
	TSharedPtr<class SDLGZWidget> DLGZWidget;//运行数据

	
	public:
	//标签栏鼠标点击
	FReply BuuttonOnClick_1();
	FReply BuuttonOnClick_2();
	FReply BuuttonOnClick_3();
	FReply BuuttonOnClick_4();
};
