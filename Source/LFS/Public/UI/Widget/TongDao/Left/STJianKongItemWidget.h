// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API STJianKongItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STJianKongItemWidget)
	{}
	SLATE_ATTRIBUTE(FString,Location)
	SLATE_ATTRIBUTE(FString,Time)
	SLATE_ATTRIBUTE(FSlateBrush,JianKongImage)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	FString Lcoation= TEXT("防火门");
	FString Time= TEXT("###");
	FSlateBrush JianKongImage;
};
