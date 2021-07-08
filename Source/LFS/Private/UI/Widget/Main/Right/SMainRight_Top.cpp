// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/Right/SMainRight_Top.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainRight_Top::Construct(const FArguments& InArgs)
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
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_Blue)
					.Text(FText::FromString(TEXT("综合看板")))
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_White)
						.Text(FText::FromString(TEXT("渝中配网负荷状态")))
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_Blue)
						.Text(FText::FromString(TEXT("正常")))
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_White)
						.Text(FText::FromString(TEXT("渝中配网运行状态")))
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_Blue)
						.Text(FText::FromString(TEXT("正常")))
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
