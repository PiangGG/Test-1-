// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/Left/SHXZBWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Left/SHuanWidget.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SUniformGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHXZBWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.WidthOverride(345.0f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Top)
				.Padding(FMargin(30,0,0,0))
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_Blue)
					.Text(FText::FromString(TEXT("核心指标")))
				]
				+SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(FMargin(30,0,50,10))
				[
					SAssignNew(HXZB_GridPanel,SUniformGridPanel)
					.SlotPadding(5.0f)
				]
			]
		]
	];

	if (HXZB_GridPanel)
	{
		HXZB_GridPanel->AddSlot(0,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SAssignNew(Huan_Zhonghe,SHuanWidget)
				.number(0.4)
				.Name(TEXT("综合指标"))
			]
		];
		HXZB_GridPanel->AddSlot(1,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SAssignNew(Huan_Zhonghe,SHuanWidget)
				.number(0.6)
				.Name(TEXT("故障率指标"))
			]
		];
		HXZB_GridPanel->AddSlot(2,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SAssignNew(Huan_Zhonghe,SHuanWidget)
				.number(0.5)
				.Name(TEXT("运维指标"))
			]
		];
	}
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
