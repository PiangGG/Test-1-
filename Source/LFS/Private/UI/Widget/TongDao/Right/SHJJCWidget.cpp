// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TongDao/Right/SHJJCWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Left/SHuanWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHJJCWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+SOverlay::Slot()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			[
				SAssignNew(HuanWidget_Wendu,SHuanWidget)
				.number(27.3f)
				.Name(TEXT("温度"))
			]
			+SHorizontalBox::Slot()
			[
				SAssignNew(HuanWidget_Wendu,SHuanWidget)
				.number(27.3f)
				.Name(TEXT("水位"))
			]
			+SHorizontalBox::Slot()
			[
				SAssignNew(HuanWidget_Wendu,SHuanWidget)
				.number(0.01f)
				.Name(TEXT("烟感"))
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
