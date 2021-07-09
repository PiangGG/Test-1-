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
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_Blue)
					.Text(FText::FromString(TEXT("告警状态")))
				]
				+SVerticalBox::Slot()
				[
					SNew(SOverlay)
					+SOverlay::Slot()
					[
						SNew(SImage)
						.Image(&MainStyle->ButtonStyle_DMY)
					]
					+SOverlay::Slot()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("隐患")))
						]
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("状态")))
						]
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("时间")))
						]
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("处理")))
						]
					]
				]
				+SVerticalBox::Slot()
				[
					SAssignNew(List,SScrollBox)
				]
			]
		]
	];
	if (List)
	{
		for(int i=0;i<8;i++)
		{
			if(i%2==0)
			{
				List->AddSlot()
				[
					SNew(SPropListItemWidget)
					.bHandle(false)
					.Time(TEXT("时间"))
					.PropName("隐患位置")
					.PropState(TEXT("正常"))
				];
			}else
			{
				List->AddSlot()
				[
					SNew(SPropListItemWidget)
					.bHandle(true)
					.Time(TEXT("时间"))
					.PropName("隐患位置")
					.PropState(TEXT("不正常"))
				];
			}
			
		}
		
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
