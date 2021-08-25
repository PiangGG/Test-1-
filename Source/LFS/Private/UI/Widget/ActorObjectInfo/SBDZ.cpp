// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ActorObjectInfo/SBDZ.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SBDZ::Construct(const FArguments& InArgs)
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
				SNew(SImage)
				.Image(&MainStyle->LeftBottom_Window4)
			]
			+SOverlay::Slot()
			[
				SNew(SBorder)
				[
					SNew(SVerticalBox)
					+SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("设备名称")))
							
						]
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_White)
						.Text(FText::FromString(TEXT("朝凯二951")))
						]
					]
					+SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("所属站房")))
							
						]
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("凯德来福士广场2#开闭所")))
						]
					]
					+SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("投运日期")))
							
						]
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_White)
						.Text(FText::FromString(TEXT("2019年5月25日")))
						]
					]
					+SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("检测日期")))
							
						]
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("2021-6-20")))
						]
					]
					+SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("开关位置")))
							
						]
						+SHorizontalBox::Slot()
						.FillWidth(1)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("2021-6-20")))
						]
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
