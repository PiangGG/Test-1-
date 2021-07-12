// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomRightBttomWidgetItem2Item.h"

#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomRightBttomWidgetItem2Item::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");

	Time=InArgs._Time.Get();
	Name=InArgs._Name.Get();
	Content=InArgs._Content.Get();
	State = InArgs._State.Get();
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
				[
					SNew(STextBlock)
					.Text(FText::FromString(Time))
					.Font(MainStyle->FontInfo_Size_12_White)
				]
				+SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(Name))
					.Font(MainStyle->FontInfo_Size_12_White)
				]
				+SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(Content))
					.Font(MainStyle->FontInfo_Size_12_White)
				]
				+SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(State))
					.Font(MainStyle->FontInfo_Size_12_White)
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
