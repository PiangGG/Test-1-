// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/Left/SMainLeftWidget.h"

#include "SlateOptMacros.h"
#include "Data/LFSDataHandle.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Left/SHXZBWidget.h"
#include "UI/Widget/Main/Left/SLineChartWidget.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainLeftWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	/*theState = LFSDataHandle::Get()->State;
	
	DistributionNetworkStatus=FString(TEXT("配网状态"))+FString(*theState[0].Find(FString("State")));
	DistributionNetworkStatusfloat=FString(*theState[0].Find(FString("percent")));

	OperationAndMaintenanceStatus=FString(TEXT("运维状态"))+FString(*theState[1].Find(FString("State")));
	OperationAndMaintenanceStatusfloat=FString(*theState[1].Find(FString("percent")));

	PowerSupplyStatus=FString(TEXT("供电状态"))+FString(*theState[2].Find(FString("State")));
	PowerSupplyStatusfloat=FString(*theState[2].Find(FString("percent")));*/
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
						.ProbarSize(FCString::Atof(*DistributionNetworkStatusfloat))
						.ShowText(TEXT("预警状态"))
						.StateImageIcon(MainStyle->StateIcon_1)
						.ProgressBarText(DistributionNetworkStatus)
					]
					+SVerticalBox::Slot()
					.AutoHeight()
					.VAlign(VAlign_Top)
					.HAlign(HAlign_Fill)
					.Padding(FMargin(30,35,20,0))
					[
						SAssignNew(Yunwei_State,SMain_Left_State_Widget)
						.ProbarSize(FCString::Atof(*OperationAndMaintenanceStatusfloat))
						.ShowText(TEXT("运维状态"))
						.StateImageIcon(MainStyle->StateIcon_2)
						.ProgressBarText(OperationAndMaintenanceStatus)
					]
					+SVerticalBox::Slot()
					.AutoHeight()
					.VAlign(VAlign_Top)
					.HAlign(HAlign_Fill)
					.Padding(FMargin(30,35,20,0))
					[
						SAssignNew(Gongdian_State,SMain_Left_State_Widget)
						.ProbarSize(FCString::Atof(*PowerSupplyStatusfloat))
						.ShowText(TEXT("供电状态"))
						.StateImageIcon(MainStyle->StateIcon_3)
						.ProgressBarText(OperationAndMaintenanceStatus)
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
