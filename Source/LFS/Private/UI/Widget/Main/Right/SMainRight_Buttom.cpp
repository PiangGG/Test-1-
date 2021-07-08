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
          		[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_16_Blue)
					.Text(FText::FromString(TEXT("管辖统计")))
          		]
          		+SVerticalBox::Slot()
          		[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SNew(SImage)
						.Image(&MainStyle->Main_Right_Buttom_Icon)
					]
					+SHorizontalBox::Slot()
					[
						SNew(SVerticalBox)
						+SVerticalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_White)
							.Text(FText::FromString(TEXT("重庆市渝中区")))
						]
						+SVerticalBox::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_Blue)
							.Text(FText::FromString(TEXT("管辖范围:18.54平方千米")))
						]
						+SVerticalBox::Slot()
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
