// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomLeftButtom_HJJCWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Left/SHuanWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomLeftButtom_HJJCWidget::Construct(const FArguments& InArgs)
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
				SAssignNew(UniformGridPanel,SUniformGridPanel)
			]	
		]
	];
	if (UniformGridPanel)
	{
		UniformGridPanel->AddSlot(0,0)
		[
			SNew(SHuanWidget)
			.number(0.25)
			.Name(TEXT("温度"))
		];
		UniformGridPanel->AddSlot(1,0)
		[
			SNew(SHuanWidget)
			.number(1-0.20)
			.Name(TEXT("湿度"))
		];
		UniformGridPanel->AddSlot(0,1)
		[
			SNew(SHuanWidget)
			.number(1-0.0)
			.Name(TEXT("臭氧"))
		];
		UniformGridPanel->AddSlot(1,1)
		[
			SNew(SHuanWidget)
			.number(1.0-0.0)
			.Name(TEXT("SF 6"))
		];
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
