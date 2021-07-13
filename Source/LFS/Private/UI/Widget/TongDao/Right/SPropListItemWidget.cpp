// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TongDao/Right/SPropListItemWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPropListItemWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");

	PropName=InArgs._PropName.Get();
	PropState=InArgs._PropState.Get();
	Time=InArgs._Time.Get();
	PropHandle=InArgs._PropHandle.Get();
	bHandle=InArgs._bHandle.Get();
	if (PropState==TEXT("正常"))
	{
		SlateFontInfo=MainStyle->FontInfo_Size_12_White;
	}else
	{
		SlateFontInfo=MainStyle->FontInfo_Size_12_Yellow;
	}

	PropHandle=bHandle?FString(TEXT("未处理")):FString(TEXT(""));
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.Padding(0,5,0,0)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(PropName))
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(SlateFontInfo)
					.Text(FText::FromString(PropState))
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(Time))
				]
				+SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(PropHandle))
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
