// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SMoitorJKWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMoitorJKWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;
};
