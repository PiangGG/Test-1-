// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Widget/Main/Buttom/SMainBottomWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Buttom/SMJianKongItemWidget.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SUniformGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainBottomWidget::Construct(const FArguments& InArgs)
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
				.Image(&MainStyle->Main_Bottom_BG)
			]
			+SOverlay::Slot()
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_Blue)
					.Text(FText::FromString(TEXT("配电统计监控")))
				]
				+SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(FMargin(00,0,0,0))
				[
					SAssignNew(Jiankong_GridPanel,SUniformGridPanel)
					.SlotPadding(0.0f)
				]
			]
		]
	];

	if (Jiankong_GridPanel)
	{
		Jiankong_GridPanel->AddSlot(0,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SAssignNew(JianKongItemWidget_kbs,SMJianKongItemWidget)
				.ImageIcon(MainStyle->ButtomIcon_1)
				.Name(TEXT("开闭所"))
				.Number(147)
				.State(TEXT("正常"))
			]
		];
		Jiankong_GridPanel->AddSlot(1,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SAssignNew(JianKongItemWidget_kbs,SMJianKongItemWidget)
				.ImageIcon(MainStyle->ButtomIcon_2)
				.Name(TEXT("配电房"))
				.Number(386)
				.State(TEXT("正常"))
			]
		];
		Jiankong_GridPanel->AddSlot(2,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SAssignNew(JianKongItemWidget_kbs,SMJianKongItemWidget)
				.ImageIcon(MainStyle->ButtomIcon_3)
				.Name(TEXT("配变台区"))
				.Number(1105)
				.State(TEXT("正常"))
			]
		];
		Jiankong_GridPanel->AddSlot(3,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SAssignNew(JianKongItemWidget_kbs,SMJianKongItemWidget)
				.ImageIcon(MainStyle->ButtomIcon_4)
				.Name(TEXT("配电线路"))
				.Number(124)
				.State(TEXT("正常"))
			]
		];
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
