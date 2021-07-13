// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/Buttom/SMJianKongItemWidget.h"

#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMJianKongItemWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	
	ImageIcon=InArgs._ImageIcon.Get();
	Name=InArgs._Name.Get();
	Number=InArgs._Number.Get();
	State=InArgs._State.Get();
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(64)
					.HeightOverride(64)
					[
						SNew(SImage)
						.Image(&ImageIcon)
					]
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				.Padding(10,0,0,0)
				[
					SNew(SVerticalBox)
					+SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(Name))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Center)
						.Padding(10,0,0,0)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_Blue)
							.Text(FText::FromString(FString::FromInt(Number)))
						]
					]
					+SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.AutoHeight()
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_Blue)
							.Text(FText::FromString(TEXT("监测状态)")))
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Center)
						.Padding(10,0,0,0)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_12_Blue)
							.Text(FText::FromString(State))
						]
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
