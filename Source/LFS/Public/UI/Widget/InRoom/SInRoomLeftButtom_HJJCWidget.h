// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SUniformGridPanel.h"

/**
 * 
 */
class LFS_API SInRoomLeftButtom_HJJCWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInRoomLeftButtom_HJJCWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	//2*2面板
	TSharedPtr<class SUniformGridPanel >UniformGridPanel;
};