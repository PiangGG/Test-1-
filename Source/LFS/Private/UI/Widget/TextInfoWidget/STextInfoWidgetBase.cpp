// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TextInfoWidget/STextInfoWidgetBase.h"
#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STextInfoWidgetBase::Construct(const FArguments& InArgs)
{
	TextImage=InArgs._TextImage.Get();
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SBorder)
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				[
					SNew(SImage)
					.Image(&TextImage)
				]
			]
		]
	];
	
}

FReply STextInfoWidgetBase::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UE_LOG(LogTemp,Warning,TEXT("STextInfoWidgetBase::OnMouseButtonUp"));
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
