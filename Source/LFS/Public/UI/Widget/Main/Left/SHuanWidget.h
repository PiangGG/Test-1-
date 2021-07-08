// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SHuanWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHuanWidget)
	{}
	SLATE_ATTRIBUTE(FString,Name)
	SLATE_ATTRIBUTE(float,number)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;
	
	UMaterialInstance* MaterialInstance;

	float number=0.0f;
	FString Name;

	TSharedPtr<class SImage> HuanImage;

	FSlateBrush* SlateBrush;
};
