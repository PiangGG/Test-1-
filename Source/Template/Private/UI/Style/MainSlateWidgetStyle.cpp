// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Style/MainSlateWidgetStyle.h"

FMainSlateStyle::FMainSlateStyle()
{
}

FMainSlateStyle::~FMainSlateStyle()
{
}

const FName FMainSlateStyle::TypeName(TEXT("FMainSlateStyle"));

const FMainSlateStyle& FMainSlateStyle::GetDefault()
{
	static FMainSlateStyle Default;
	return Default;
}

void FMainSlateStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

