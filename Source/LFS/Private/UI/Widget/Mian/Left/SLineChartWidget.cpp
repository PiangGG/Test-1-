// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Widget/Mian/Left/SLineChartWidget.h"

#include "SlateOptMacros.h"
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
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_Blue)
						.Text(FText::FromString(TEXT("负荷曲线")))
					]
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Center)
					[
						SAssignNew(DMY_GridPanel,SUniformGridPanel)
						.SlotPadding(5.0f)
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
				//.OnClicked(this,&SLineChartWidget::ButtonOnclick)
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
			]
		];
	}
}

void SLineChartWidget::ButtonOnclick()
{
	//switch (EXPRESSION) {  }
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.0,FColor::Yellow,FString("OnClick"));
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
