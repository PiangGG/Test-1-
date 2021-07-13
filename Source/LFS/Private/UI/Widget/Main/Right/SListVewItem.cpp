// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/Right/SListVewItem.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SListViewItem::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");

	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.Padding(0,5,5,0)
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(name))
				]
				+SHorizontalBox::Slot()
				.Padding(0,5,5,0)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.FillWidth(0.5f)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_Blue)
					.Text(FText::FromString(state))
				]
				+SHorizontalBox::Slot()
				.Padding(0,5,5,0)
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(xiangqing))
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
