// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Tongdao/Right/SRight_Main.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/TongDao/Right/SGJZTWidget.h"
#include "UI/Widget/TongDao/Right/SHJJCWidget.h"
#include "UI/Widget/TongDao/Right/SSBZXWidget.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRight_Main::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget

		SNew(SOverlay)
		+SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0,25,0,0))
		[
			SNew(SImage)
			.Image(&MainStyle->TD_BG_RIGHT)
		]
		+SOverlay::Slot()
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Fill)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.Padding(FMargin(30,90,0,0))
			.AutoHeight()
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_16_Blue)
				.Text(FText::FromString(TEXT("环境监测")))
			]
			+SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(30,0,0,0))
			[
				SAssignNew(HJJCWidget,SHJJCWidget)
			]
			+SVerticalBox::Slot()
			.AutoHeight()
			[
				SAssignNew(SBZXWidget,SSBZXWidget)
			]
			+SVerticalBox::Slot()
			.AutoHeight()
			[
				SAssignNew(GJZTWidget,SGJZTWidget)
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
