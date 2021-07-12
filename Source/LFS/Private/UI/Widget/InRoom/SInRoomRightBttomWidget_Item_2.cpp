// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomRightBttomWidget_Item_2.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/InRoom/SInRoomRightBttomWidgetItem2Item.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SUniformGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomRightBttomWidget_Item_2::Construct(const FArguments& InArgs)
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
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				[
					SAssignNew(Button_UniformGridPanel,SUniformGridPanel)
				]
				+SVerticalBox::Slot()
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
						[
							SNew(STextBlock)
							.Text(FText::FromString(TEXT("告警时间")))
							.Font(MainStyle->FontInfo_Size_12_White)
						]
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Text(FText::FromString(TEXT("设备名称")))
							.Font(MainStyle->FontInfo_Size_12_White)
						]
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Text(FText::FromString(TEXT("告警内容")))
							.Font(MainStyle->FontInfo_Size_12_White)
						]
						+SHorizontalBox::Slot()
						[
							SNew(STextBlock)
							.Text(FText::FromString(TEXT("处理状态")))
							.Font(MainStyle->FontInfo_Size_12_White)
						]
					]
				]
				+SVerticalBox::Slot()
				[
					SAssignNew(List,SScrollBox)
				]
			]
		]
	];

	if (Button_UniformGridPanel)
	{
		Button_UniformGridPanel->AddSlot(0,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_12_White)
				.Text(FText::FromString(TEXT("当日告警")))
			]
			
			+SOverlay::Slot()
			[
				SAssignNew(Button_Day,SButton)
				.ButtonStyle(&MainStyle->ButtonStyle_DMY)
				.OnClicked(this,&SInRoomRightBttomWidget_Item_2::Button_Day_OnClick)
				//.OnClicked(this,&SLineChartWidget::ButtonOnclick)
			]
		];
		Button_UniformGridPanel->AddSlot(1,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_12_White)
				.Text(FText::FromString(TEXT("当月告警")))
			]
			+SOverlay::Slot()
			[
				SAssignNew(Button_Day,SButton)
				.ButtonStyle(&MainStyle->ButtonStyle_DMY)
				.OnClicked(this,&SInRoomRightBttomWidget_Item_2::Button_Month_OnClick)
			]
		];
		Button_UniformGridPanel->AddSlot(2,0)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_12_White)
				.Text(FText::FromString(TEXT("本年告警")))
			]
			+SOverlay::Slot()
			[
				SAssignNew(Button_Day,SButton)
				.ButtonStyle(&MainStyle->ButtonStyle_DMY)
				.OnClicked(this,&SInRoomRightBttomWidget_Item_2::Button_Year_OnClick)
			]
		];
	}
	if (List)
	{
		List->ClearChildren();
		for (int i=0;i<10;i++)
		{
			List->AddSlot()
			[
				SNew(SInRoomRightBttomWidgetItem2Item)
				.Time(TEXT("Time:"))
				.Name(TEXT("设备名字"))
				.Content(TEXT("告警内容"))
				.State(TEXT("未处理"))
			];
		}	
	}
}

FReply SInRoomRightBttomWidget_Item_2::Button_Day_OnClick()
{
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.0,FColor::Yellow,FString("当日警告"));
	}
	return FReply::Handled();
}

FReply SInRoomRightBttomWidget_Item_2::Button_Month_OnClick()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.0,FColor::Yellow,FString("当月警告"));
	}
	return FReply::Handled();
}

FReply SInRoomRightBttomWidget_Item_2::Button_Year_OnClick()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.0,FColor::Yellow,FString("当年警告"));
	}
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
