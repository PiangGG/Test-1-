// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomRightTopWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/InRoom/SInRoomRightTopItemWidget.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SScrollBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomRightTopWidget::Construct(const FArguments& InArgs)
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
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(&MainStyle->InRoomplan)
			]
			+SOverlay::Slot()
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.AutoHeight()
				.Padding(20,20,0,0)
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("辅控管理")))
					.Font(MainStyle->FontInfo_Size_16_Blue)
				]
				+SVerticalBox::Slot()
				.Padding(13,20,13,0)
				.AutoHeight()
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
							.Text(FText::FromString(TEXT("名称")))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("型号")))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("状态")))
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
		for (int i=0;i<20;i++)
		{
			List->AddSlot()
			[
				SNew(SInRoomRightTopItemWidget)
				.Name(TEXT("名称1"))
				.Type(TEXT("型号1"))
				.State(TEXT("状态1"))
			];
		}
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
