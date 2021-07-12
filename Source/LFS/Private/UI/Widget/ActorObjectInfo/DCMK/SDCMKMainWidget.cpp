// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ActorObjectInfo/DCMK/SDCMKMainWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/ActorObjectInfo/DCMK/SDC_ItemWidget.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SUniformGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SDCMKMainWidget::Construct(const FArguments& InArgs)
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
				.Image(&MainStyle->ObjectActorInfo_BG)
			]
			+SOverlay::Slot()
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_White)
					.Text(FText::FromString(TEXT("设备信息")))
				]
				+SVerticalBox::Slot()
				[
					SAssignNew(UniformGridPanel,SUniformGridPanel)
				]
			]
		]
	];

	if (UniformGridPanel)
	{
		UniformGridPanel->AddSlot(0,0)
		[
			SNew(SDC_ItemWidget)
			.Neizu(0.4)
			.JZWD(0.2)
			.Number_1(1)
			.Number_2(1-0.3)
			.Number_3(1-0.2)
			.DC_Name(TEXT("1#电池模块运行状况"))
			.DC_WorkState(TEXT("浮充"))
		];
		UniformGridPanel->AddSlot(0,1)
		[
			SNew(SDC_ItemWidget)
			.Neizu(0.5)
			.JZWD(0.2)
			.Number_1(0.75)
			.Number_2(1-0.3)
			.Number_3(1-0.3)
			.DC_Name(TEXT("2#电池模块运行状况"))
			.DC_WorkState(TEXT("浮充"))
		];
		UniformGridPanel->AddSlot(1,0)
		[
			SNew(SDC_ItemWidget)
			.Neizu(0.4)
			.JZWD(0.21)
			.Number_1(0.76)
			.Number_2(1-0.2)
			.Number_3(1-0.2)
			.DC_Name(("3#电池模块运行状况"))
			.DC_WorkState(TEXT("浮充"))
		];
		UniformGridPanel->AddSlot(1,1)
		[
			SNew(SDC_ItemWidget)
			.Neizu(0.5)
			.JZWD(0.19)
			.Number_1(0.7)
			.Number_2(1-0.2)
			.Number_3(1-0.3)
			.DC_Name(TEXT("4#电池模块运行状况"))
			.DC_WorkState(TEXT("浮充"))
		];
		
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
