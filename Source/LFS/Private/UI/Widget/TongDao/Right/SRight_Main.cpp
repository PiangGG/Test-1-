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
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		[
			SNew(SImage)
			.Image(&MainStyle->Main_Right_BG)
		]
		+SOverlay::Slot()
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_16_Blue)
				.Text(FText::FromString(TEXT("环境监测")))
			]
			+SVerticalBox::Slot()
			[
				SAssignNew(HJJCWidget,SHJJCWidget)
			]
			+SVerticalBox::Slot()
			[
				SAssignNew(SBZXWidget,SSBZXWidget)
			]
			+SVerticalBox::Slot()
			[
				SAssignNew(GJZTWidget,SGJZTWidget)
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
