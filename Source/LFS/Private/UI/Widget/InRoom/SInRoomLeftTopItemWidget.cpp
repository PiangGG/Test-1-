// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomLeftTopItemWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomLeftTopItemWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	name=InArgs._name.Get();
	level=InArgs._level.Get();
	Type=InArgs._Type.Get();
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.Padding(0,5,0,0)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(name))
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(level))
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(Type))
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
