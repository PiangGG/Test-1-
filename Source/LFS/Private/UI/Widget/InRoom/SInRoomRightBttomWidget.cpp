// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomRightBttomWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/InRoom/SInRoomRightButtomItemWidget.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SScrollBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomRightBttomWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.HeightOverride(470)
		.WidthOverride(350)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SNew(SImage)
				.Image(&MainStyle->InRoomplan)	
			]
			+SOverlay::Slot()
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.Padding(20,20,0,0)
				.AutoHeight()
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("缺陷状态管理")))
					.Font(MainStyle->FontInfo_Size_16_Blue)
				]
				+SVerticalBox::Slot()
				.AutoHeight()
				.Padding(13,20,13,0)
				[
					SNew(SOverlay)
					+SOverlay::Slot()
					[
						SNew(SImage)
						.Image(&MainStyle->Main_Right_Infotitle)
					]
					+SOverlay::Slot()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("设备")))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("缺陷")))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("时间")))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("处理")))
						]
					]
				]
				+SVerticalBox::Slot()
				.Padding(13,5,10,0)
				.MaxHeight(335.0f)
				[
					SAssignNew(List,SScrollBox)
				]
			]
			
		]
	];
	if (List)
	{
		List->ClearChildren();
		for (int i=0;i<25;i++)
		{
			List->AddSlot()
			[
				SNew(SInRoomRightButtomItemWidget)
				.Prop(TEXT("设备名称"))
				.Defect(TEXT("无"))
				.Time(TEXT("Time"))
				.Handle(TEXT("检修"))
			];
		}
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
