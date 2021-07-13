// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TongDao/Right/SSBZXWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSBZXWidget::Construct(const FArguments& InArgs)
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
					.Text(FText::FromString(TEXT("设备在线")))
				]
				+SVerticalBox::Slot()
				.Padding(20,25,25,0)
				[
					SAssignNew(SLFSProgressbar_Ganzhi,SLFSProgressbar)
					.percent(1.0f)
					.Name(TEXT("感知设备"))
				]
				+SVerticalBox::Slot()
				.Padding(20,25,25,0)
				[
					SAssignNew(SLFSProgressbar_Ganzhi,SLFSProgressbar)
					.percent(1.0f)
					.Name(TEXT("视频监控"))
				]
				+SVerticalBox::Slot()
				.Padding(20,25,25,0)
				[
					SAssignNew(SLFSProgressbar_Ganzhi,SLFSProgressbar)
					.percent(1.0f)
					.Name(TEXT("照明设备"))
				]
				+SVerticalBox::Slot()
				.Padding(20,25,25,0)
				[
					SAssignNew(SLFSProgressbar_Ganzhi,SLFSProgressbar)
					.percent(0.98f)
					.Name(TEXT("消防设备"))
				]
				+SVerticalBox::Slot()
				.Padding(20,25,25,0)
				[
					SAssignNew(SLFSProgressbar_Ganzhi,SLFSProgressbar)
					.percent(0.95f)
					.Name(TEXT("其他设备"))
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
