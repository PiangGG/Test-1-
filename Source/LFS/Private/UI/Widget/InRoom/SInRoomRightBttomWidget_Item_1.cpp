// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomRightBttomWidget_Item_1.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Left/SHuanWidget.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SUniformGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomRightBttomWidget_Item_1::Construct(const FArguments& InArgs)
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
				SNew(SImage)
				.Image(&MainStyle->LeftBottom_Window1)
			]
			+SOverlay::Slot()
			.Padding(FMargin(30.0f))
			[
				SAssignNew(UniformGridPanel,SUniformGridPanel)
				.SlotPadding(20.0f)
			]
		]
	];

	if (UniformGridPanel)
	{
		UniformGridPanel->AddSlot(0,0)
		[
			SNew(SHuanWidget)
			.number(1-0.25)
			.Name(TEXT("温度"))
		];
		UniformGridPanel->AddSlot(1,0)
		[
			SNew(SHuanWidget)
			.number(1)
			.Name(TEXT("臭氧"))
		];
		UniformGridPanel->AddSlot(2,0)
		[
			SNew(SHuanWidget)
			.number(1)
			.Name(TEXT("SF 6"))
		];
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
