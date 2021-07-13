// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ActorObjectInfo/SDLXXWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SDLXXWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.WidthOverride(600.f)
		.HeightOverride(800.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(&MainStyle->Center_Window)
			]
			+SOverlay::Slot()
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("线路名称")))	
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("10千伏临德线")))	
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("电压等级")))	
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("10千伏")))	
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("敷设方式")))	
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("隧道敷设")))	
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("线路长度")))	
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("2.4公里")))	
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("起始位置")))	
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("临江门变电站648开关")))	
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("终止位置")))	
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("来福士广场")))	
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("电缆型号")))	
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("YJV22-3*400")))	
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("生产厂家")))	
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("重庆鸽牌电线电缆有限公司")))	
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("投运日期")))	
					]
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("年月日")))	
					]
				]
			]
		]
		
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION