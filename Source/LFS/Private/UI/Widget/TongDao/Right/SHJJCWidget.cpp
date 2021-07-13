// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TongDao/Right/SHJJCWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Left/SHuanWidget.h"
#include "Widgets/Layout/SUniformGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHJJCWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.WidthOverride(345.0f)
		.HeightOverride(100)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.Padding(FMargin(0,0,20,0))
			[
				SAssignNew(UniformGridPanel,SUniformGridPanel)
				.SlotPadding(10)
			]
		]
		
	];
	if (UniformGridPanel)
	{
		UniformGridPanel->AddSlot(0,0)
		[
			SAssignNew(HuanWidget_Wendu,SHuanWidget)
			.number(27.3f)
			.Name(TEXT("温度"))
		];
		UniformGridPanel->AddSlot(1,0)
		[
		SAssignNew(HuanWidget_Wendu,SHuanWidget)
				.number(27.3f)
				.Name(TEXT("水位"))
		];
		UniformGridPanel->AddSlot(2,0)
		[
		SAssignNew(HuanWidget_Wendu,SHuanWidget)
				.number(0.01f)
				.Name(TEXT("烟感"))
		];
	}
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
