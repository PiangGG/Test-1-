// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TongDao/Right/SGJZTWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/TongDao/Right/SPropListItemWidget.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SScrollBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SGJZTWidget::Construct(const FArguments& InArgs)
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
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				.AutoHeight()
				.Padding(20,20,0,0)
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_Blue)
					.Text(FText::FromString(TEXT("告警状态")))
				]
				+SVerticalBox::Slot()
				.AutoHeight()
				.Padding(20,20,0,0)
				[
					
					SNew(SOverlay)
					+SOverlay::Slot()
					.Padding(0,0,30,0)
					[
						SNew(SBox)
						[
							SNew(SImage)
							.Image(&MainStyle->Main_Right_Infotitle)
						]
					]
					+SOverlay::Slot()
					.Padding(0,0,30,0)
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("隐患")))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("状态")))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("时间")))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("处理")))
						]
					]
				]	
				+SVerticalBox::Slot()
				.Padding(20,20,20,0)
				.MaxHeight(400.0f)
				[
					SAssignNew(List,SScrollBox)
				]
			]
		]
	];
	if (List)
	{
		for(int i=0;i<50;i++)
		{
			if(i%2==0)
			{
				List->AddSlot()
				[
					SNew(SPropListItemWidget)
					.bHandle(false)
					.Time(TEXT("时间"))
					.PropName(TEXT("隐患位置"))
					.PropState(TEXT("正常"))
				];
			}else
			{
				List->AddSlot()
				[
					SNew(SPropListItemWidget)
					.bHandle(true)
					.Time(TEXT("时间"))
					.PropName(TEXT("隐患位置"))
					.PropState(TEXT("不正常"))
				];
			}
			
		}
		
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
