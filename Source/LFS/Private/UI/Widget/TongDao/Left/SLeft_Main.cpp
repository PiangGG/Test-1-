// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TongDao/Left/SLeft_Main.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/TongDao/Left/STJianKongItemWidget.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/STextComboBox.h"
#include "Widgets/Layout/SScrollBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLeft_Main::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	Array_floor.Add(MakeShareable(new FString(TEXT("来福士1楼"))));
	Array_floor.Add(MakeShareable(new FString(TEXT("来福士2楼"))));
	Array_floor.Add(MakeShareable(new FString(TEXT("来福士3楼"))));

	Array_Location.Add(MakeShareable(new FString(TEXT("监控位置1"))));
	Array_Location.Add(MakeShareable(new FString(TEXT("监控位置2"))));
	Array_Location.Add(MakeShareable(new FString(TEXT("监控位置3"))));
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(FMargin(0,25,0,0))
			[
				SNew(SImage)
				.Image(&MainStyle->Main_Left_BG)
			]
			+SOverlay::Slot()
			.VAlign(VAlign_Top)
			.HAlign(HAlign_Fill)
			.Padding(FMargin(0,105,0,0))
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
					.Padding(FMargin(10,0,0,0))
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_Blue)
						.Text(FText::FromString(TEXT("监控总览")))
					]
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(SBorder)
						[
							SAssignNew(TextComboBox_floor,STextComboBox)
							.OptionsSource(&Array_floor)
							.Font(MainStyle->FontInfo_Size_12_White)
							.ComboBoxStyle(&MainStyle->ComboBoStyle)
							.ColorAndOpacity(MainStyle->ComboBoStyleColor)
							.ButtonStyle(&MainStyle->ComboBoxButtonStyle)
						]
					]
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(SBorder)
						[
							SAssignNew(TextComboBox_Location,STextComboBox)
							.OptionsSource(&Array_Location)
							.Font(MainStyle->FontInfo_Size_12_White)
							.ComboBoxStyle(&MainStyle->ComboBoStyle)
							.ColorAndOpacity(MainStyle->ComboBoStyleColor)
							.ButtonStyle(&MainStyle->ComboBoxButtonStyle)
						]
					]
				]
				+SVerticalBox::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Fill)
				.MaxHeight(850.f)
				.Padding(FMargin(0,20,0,0))
				[
					SAssignNew(JiankongList,SScrollBox)
				]
			]
		]
	];
	if (TextComboBox_floor)
	{
		TextComboBox_floor->SetSelectedItem(Array_floor[0]);
	}
	if (TextComboBox_Location)
	{
		TextComboBox_Location->SetSelectedItem(Array_Location[0]);
	}
	if (JiankongList)
	{
		//根据数据库数据确定列表长度
		for (int i=0;i<10;i++)
		{
			JiankongList->AddSlot()
			[
				SNew(STJianKongItemWidget)
				.Location(TEXT("位置"))
				.Time(TEXT("时间"))
				.JianKongImage(MainStyle->Main_Window)
			];
		}
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
