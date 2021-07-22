// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ActorObjectInfo/SMoitorJKWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMoitorJKWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.WidthOverride(300.0f)
		.HeightOverride(200.0f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				
				SNew(SImage)
				.Image(&MainStyle->LeftBottom_Window4)
			]
			+SOverlay::Slot()
			.VAlign(VAlign_Top)
			.HAlign(HAlign_Left)
			.Padding(FMargin(40,-32,0,0))
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				[
					SNew(SImage)
					.Image(&MainStyle->TD_LB)
				]
				+SOverlay::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_White)
					.Text(FText::FromString(TEXT("监控画面")))
				]
			]
			+SOverlay::Slot()
			.Padding(FMargin(10.0f))
			[
				SNew(SImage)
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
