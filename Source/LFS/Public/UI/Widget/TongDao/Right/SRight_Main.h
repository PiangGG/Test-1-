// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SRight_Main : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRight_Main)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	TSharedPtr<class SHJJCWidget> HJJCWidget;
	TSharedPtr<class SSBZXWidget> SBZXWidget;
	TSharedPtr<class SGJZTWidget> GJZTWidget;
};
