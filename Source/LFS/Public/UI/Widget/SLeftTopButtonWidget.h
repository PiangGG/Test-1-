// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
UENUM()
enum class EButtonStyle:uint8
{
	Swtich,Reset,Back
};

class LFS_API SLeftTopButtonWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLeftTopButtonWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	EButtonStyle ButtonStyle=EButtonStyle::Swtich;

	FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply OnButtonOnclick();

	TSharedPtr<class STextBlock> TextBlock;
	FText ShowText=FText::FromString("切换");
};

