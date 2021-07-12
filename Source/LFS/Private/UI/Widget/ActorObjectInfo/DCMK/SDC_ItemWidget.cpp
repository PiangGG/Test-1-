// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Widget/ActorObjectInfo/DCMK/SDC_ItemWidget.h"

#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/SLFSProgressbar.h"
#include "UI/Widget/Main/Left/SHuanWidget.h"
#include "Widgets/Layout/SUniformGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SDC_ItemWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");

	JZWD=InArgs._JZWD.Get();
	Neizu=InArgs._Neizu.Get();
	
	DC_Name=InArgs._DC_Name.Get();
	DC_ZGJ=InArgs._DC_ZGJ.Get();
	DC_WorkState=InArgs._DC_WorkState.Get();

	Number_1=InArgs._Number_1.Get();
	Number_2=InArgs._Number_2.Get();
	Number_3=InArgs._Number_3.Get();
	
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
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(DC_Name))
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("总告警")))
						]
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(DC_ZGJ))
						]
					]
					+SHorizontalBox::Slot()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("工作状态")))
						]
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(DC_WorkState))
						]
					]
				]
				+SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SAssignNew(Progressbar_1,SLFSProgressbar)
						.percent(JZWD)
						.Name(TEXT("脊柱温度"))
						.Number(FString::SanitizeFloat(JZWD*100)+"℃")
					]
					+SHorizontalBox::Slot()
					[
						SAssignNew(Progressbar_1,SLFSProgressbar)
						.percent(Neizu)
						.Name(TEXT("内阻"))
						.Number(FString::SanitizeFloat(Neizu*100)+"mΩ")
					]
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
			SNew(SHuanWidget)
			.number(Number_1)
			.Name(TEXT("输出电压"))
		];
		UniformGridPanel->AddSlot(0,1)
		[
			SNew(SHuanWidget)
			.number(Number_2)
			.Name(TEXT("输出电流"))
		];
		UniformGridPanel->AddSlot(0,2)
		[
			SNew(SHuanWidget)
			.number(Number_3)
			.Name(TEXT("电池电流"))
		];
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
