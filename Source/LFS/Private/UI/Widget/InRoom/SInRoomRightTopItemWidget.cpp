// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomRightTopItemWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomRightTopItemWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	Name=InArgs._Name.Get();
	Type=InArgs._Type.Get();
	State=InArgs._State.Get();
	
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.Padding(10,20,10,0)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(Name))
				]
				+SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(Type))
				]
				+SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Font(MainStyle->FontInfo_Size_12_White)
					.Text(FText::FromString(State))
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
