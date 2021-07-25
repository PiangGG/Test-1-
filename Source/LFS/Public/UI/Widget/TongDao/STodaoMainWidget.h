// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API STodaoMainWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STodaoMainWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SLeft_Main> Left_Main;
	
	TSharedPtr<class SRight_Main> Right_Main;
	
	TSharedPtr<class SMainTopWidget> MainTopWidget;

	
};
