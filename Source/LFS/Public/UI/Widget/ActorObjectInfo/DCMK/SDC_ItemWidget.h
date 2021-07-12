// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class LFS_API SDC_ItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDC_ItemWidget)
	{}
	SLATE_ATTRIBUTE(FString,DC_Name)
	SLATE_ATTRIBUTE(FString,DC_ZGJ)
	SLATE_ATTRIBUTE(FString,DC_WorkState)
	SLATE_ATTRIBUTE(float,JZWD)
	SLATE_ATTRIBUTE(float,Neizu)
	SLATE_ATTRIBUTE(float,Number_1)
	SLATE_ATTRIBUTE(float,Number_2)
	SLATE_ATTRIBUTE(float,Number_3)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	FString DC_Name=TEXT("1#电池模块运行状况");
	FString DC_ZGJ=TEXT("正常");
	FString DC_WorkState=TEXT("浮充");
	TSharedPtr<class SLFSProgressbar> Progressbar_1;
	TSharedPtr<class SLFSProgressbar> Progressbar_2;
	TSharedPtr<class SUniformGridPanel>UniformGridPanel;

	float JZWD=0.0f;
	float Neizu=0.0f;

	float Number_1;
	float Number_2;
	float Number_3;
};
