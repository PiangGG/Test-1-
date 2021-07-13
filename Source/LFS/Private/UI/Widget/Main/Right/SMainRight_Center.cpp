// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/Right/SMainRight_Center.h"
#include "SlateOptMacros.h"
#include "Slate/Private/Widgets/Views/SListPanel.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Right/SListVewItem.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Views/SListView.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainRight_Center::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");

	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.AutoHeight()
			.Padding(30,60,0,0)
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_16_Blue)
				.Text(FText::FromString(TEXT("全配网运行状态")))
			]
			+SVerticalBox::Slot()
			.Padding(15,10,15,0)
			.AutoHeight()
			.HAlign(HAlign_Fill)
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				.VAlign(VAlign_Fill)
				.HAlign(HAlign_Fill)
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
						.Text(FText::FromString(TEXT("状态")))
					]
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_12_White)
						.Text(FText::FromString(TEXT("详情")))
					]
				]
			]
			+SVerticalBox::Slot()
			.Padding(15,10,10,0)
			.MaxHeight(520.f)
			[
				SAssignNew(listView,SScrollBox)
			]
		]
	];
	if (listView)
	{
		listView->ClearChildren();
		for (int i=0;i<50;i++)
		{
			listView->AddSlot()
			[
				SNew(SListViewItem)
			];
		}
		
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
