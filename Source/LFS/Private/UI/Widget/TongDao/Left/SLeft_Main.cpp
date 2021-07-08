// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TongDao/Left/SLeft_Main.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/TongDao/Left/STJianKongItemWidget.h"
#include "Widgets/Input/STextComboBox.h"
#include "Widgets/Layout/SScrollBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLeft_Main::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	Array_floor.Add(MakeShareable(new FString("来福士1楼")));
	Array_floor.Add(MakeShareable(new FString("来福士2楼")));
	Array_floor.Add(MakeShareable(new FString("来福士3楼")));

	Array_Location.Add(MakeShareable(new FString("监控位置1")));
	Array_Location.Add(MakeShareable(new FString("监控位置2")));
	Array_Location.Add(MakeShareable(new FString("监控位置3")));
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
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Font(MainStyle->FontInfo_Size_16_White)
						.Text(FText::FromString(TEXT("监控总览")))
					]
					+SHorizontalBox::Slot()
					[
						SAssignNew(TextComboBox_floor,STextComboBox)
						.OptionsSource(&Array_floor)
					]
					+SHorizontalBox::Slot()
					[
						SAssignNew(TextComboBox_floor,STextComboBox)
						.OptionsSource(&Array_Location)
					]
				]
				+SVerticalBox::Slot()
				[
					SAssignNew(JiankongList,SScrollBox)
				]
			]
		]
	];
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
