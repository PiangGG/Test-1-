// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/Right/SMainRight_Buttom.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainRight_Buttom::Construct(const FArguments& InArgs)
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
          		.Padding(30,50,0,0)
          		[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_Blue)
					.Text(FText::FromString(TEXT("管辖统计")))
          		]
          		+SVerticalBox::Slot()
          		.VAlign(VAlign_Center)
          		.Padding(30,-20,0,0)
          		[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(64)
						.HeightOverride(128)
						[
							SNew(SImage)
							.Image(&MainStyle->Main_Right_Buttom_Icon)
						]
					]
					+SHorizontalBox::Slot()
					.Padding(10,0,0,0)
					[
						SNew(SVerticalBox)
						+SVerticalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("重庆市渝中区")))
						]
						+SVerticalBox::Slot()
						.Padding(0,10,0,0)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_Blue)
							.Text(FText::FromString(TEXT("管辖范围:18.54平方千米")))
						]
						+SVerticalBox::Slot()
						.Padding(0,10,0,0)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_Blue)
							.Text(FText::FromString(TEXT("用户数量:352万")))
						]
					]
          		]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
