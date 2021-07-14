// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/Left/SMainLeftWidget.h"

#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Left/SHXZBWidget.h"
#include "UI/Widget/Main/Left/SLineChartWidget.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainLeftWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SBorder)
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				[
					SNew(SImage)
					.Image(&MainStyle->Main_Left_BG)
				]
				+SOverlay::Slot()
				.VAlign(VAlign_Top)
				.HAlign(HAlign_Fill)
				.Padding(FMargin(30,20,0,0))
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_Blue)
					.Text(FText::FromString(TEXT("状态监测")))
				]
				+SOverlay::Slot()
				[
					SNew(SVerticalBox)
					+SVerticalBox::Slot()
					.AutoHeight()
					.VAlign(VAlign_Top)
					.HAlign(HAlign_Fill)
					.Padding(FMargin(30,90,20,0))
					[
						SAssignNew(Yujing_State,SMain_Left_State_Widget)
						.ProbarSize(0.4)
						.ShowText(TEXT("预警状态"))
						.StateImageIcon(MainStyle->StateIcon_1)
						.ProgressBarText(TEXT("配网状态正常"))
					]
					+SVerticalBox::Slot()
					.AutoHeight()
					.VAlign(VAlign_Top)
					.HAlign(HAlign_Fill)
					.Padding(FMargin(30,35,20,0))
					[
						SAssignNew(Yunwei_State,SMain_Left_State_Widget)
						.ProbarSize(0.5)
						.ShowText(TEXT("运维状态"))
						.StateImageIcon(MainStyle->StateIcon_2)
						.ProgressBarText(TEXT("运维状态正常"))
					]
					+SVerticalBox::Slot()
					.AutoHeight()
					.VAlign(VAlign_Top)
					.HAlign(HAlign_Fill)
					.Padding(FMargin(30,35,20,0))
					[
						SAssignNew(Gongdian_State,SMain_Left_State_Widget)
						.ProbarSize(0.45)
						.ShowText(TEXT("供电状态"))
						.StateImageIcon(MainStyle->StateIcon_3)
						.ProgressBarText(TEXT("供电状态正常"))
					]
					+SVerticalBox::Slot()
					//.AutoHeight()
					.VAlign(VAlign_Fill)
					.HAlign(HAlign_Fill)
					.Padding(FMargin(0,0,-5,0))
					[
						SAssignNew(LineChartWidget,SLineChartWidget)
					]
					+SVerticalBox::Slot()
					.VAlign(VAlign_Bottom)
					.HAlign(HAlign_Fill)
					.Padding(FMargin(0,0,0,50))
					[
						SAssignNew(HXZBWidget,SHXZBWidget)
					]
				]
			]
		]
	];
	
}



END_SLATE_FUNCTION_BUILD_OPTIMIZATION
