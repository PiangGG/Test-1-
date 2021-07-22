// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
DECLARE_DELEGATE(FOnClickedImage)
class LFS_API STextInfoWidgetBase : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STextInfoWidgetBase)
	{}
	
	SLATE_ATTRIBUTE(FSlateBrush,TextImage)
	SLATE_EVENT(FOnClickedImage,OnClickedImage)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//引入Sytle|获取MenuStyle
	const struct FMainSlateStyle* MainStyle;

	UFUNCTION()
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	UFUNCTION()
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	
	UFUNCTION()
	virtual void SetLocationActor(AActor* Actor);
	
	FSlateBrush TextImage;
private:
	FOnClickedImage OnClickedImage;
private:
	AActor* LocationActor=nullptr;
};
