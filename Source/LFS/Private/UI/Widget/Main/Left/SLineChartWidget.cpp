// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Widget/Main/Left/SLineChartWidget.h"

#include "SlateOptMacros.h"
#include "SWebBrowser.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "Widgets/Layout/SUniformGridPanel.h"
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLineChartWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Top)
				.Padding(FMargin(0,20,0,0))
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Top)
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_Blue)
						.Text(FText::FromString(TEXT("负荷曲线")))
					]
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Top)
					[
						SAssignNew(DMY_GridPanel,SUniformGridPanel)
						.SlotPadding(5.0f)
					]
				]
				+SVerticalBox::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Top)
				.Padding(FMargin(0,-55,0,0))
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Top)
					.Padding(FMargin(30,0,0,0))
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("当前总负荷:")))
						.Font(MainStyle->FontInfo_Size_16_White)
					]
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Top)
					.Padding(FMargin(0,0,0,0))
					[
						SAssignNew(TextBlock_CurrentTotalload,STextBlock)
						.Font(MainStyle->FontInfo_Size_12_Blue)
						.Text(FText::FromString(FString::SanitizeFloat(CurrentTotalload_Num)+"W"))//显示当前总负荷
						//.MinDesiredWidth(20.0f)
					]
				]
				+SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(FMargin(0,-50,0,0))
				[
					SNew(SBox)
					.HeightOverride(300.0f)
					.WidthOverride(300.0f)
					[
						SAssignNew(EChart_WebBrowser, SWebBrowser)
						.ViewportSize(300.0)
						.ShowAddressBar(false)
						.ShowControls(false)
						.ShowInitialThrobber(false)
						.SupportsTransparency(true)
					]
					
				]
			]
		]
	];
	if (DMY_GridPanel)
	{
		DMY_GridPanel->AddSlot(0,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_12_White)
				.Text(FText::FromString(TEXT("当日")))
			]
			
			+SOverlay::Slot()
			[
				SAssignNew(Button_Day,SButton)
				.ButtonStyle(&MainStyle->ButtonStyle_DMY)
				.OnClicked(this,&SLineChartWidget::Button_Day_OnClick)
			]
		];
		DMY_GridPanel->AddSlot(1,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_12_White)
				.Text(FText::FromString(TEXT("月度")))
			]
			+SOverlay::Slot()
			[
				SAssignNew(Button_Day,SButton)
				.ButtonStyle(&MainStyle->ButtonStyle_DMY)
				.OnClicked(this,&SLineChartWidget::Button_Month_OnClick)
			]
		];
		DMY_GridPanel->AddSlot(2,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_12_White)
				.Text(FText::FromString(TEXT("年度")))
			]
			+SOverlay::Slot()
			[
				SAssignNew(Button_Day,SButton)
				.ButtonStyle(&MainStyle->ButtonStyle_DMY)
				.OnClicked(this,&SLineChartWidget::Button_Year_OnClick)
			]
		];
		if (EChart_WebBrowser)
		{
			FString URL=FString("D:/Code/unrealengine/LFS/Content/Echarts/histogram/index.html");
			EChart_WebBrowser->LoadURL(URL);
			UE_LOG(LogTemp,Warning,TEXT("%s"),*URL);
		}
	}
}

float SLineChartWidget::GetCurrentTotalload_Num()
{
	return CurrentTotalload_Num;
}

void SLineChartWidget::SetCurrentTotalload_Num(float var)
{
	CurrentTotalload_Num=var;
	return;
}

FReply SLineChartWidget::Button_Day_OnClick()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.0,FColor::Yellow,FString("当日"));
	}
	return FReply::Handled();
}

FReply SLineChartWidget::Button_Month_OnClick()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.0,FColor::Yellow,FString("月度"));
	}
	return FReply::Handled();
}

FReply SLineChartWidget::Button_Year_OnClick()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.0,FColor::Yellow,FString("年度"));
	}
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
