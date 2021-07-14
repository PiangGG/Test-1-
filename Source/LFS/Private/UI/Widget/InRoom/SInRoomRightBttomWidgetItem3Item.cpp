// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomRightBttomWidgetItem3Item.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomRightBttomWidgetItem3Item::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	Time=InArgs._Time.Get();
	Content=InArgs._Content.Get();
	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+SOverlay::Slot()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.FillWidth(1)
			[
				SNew(STextBlock)
				.Text(FText::FromString(Time))
				.Font(MainStyle->FontInfo_Size_12_White)
			]
			+SHorizontalBox::Slot()
			.FillWidth(3)
			[
				SNew(STextBlock)
				.Text(FText::FromString(Content))
				.Font(MainStyle->FontInfo_Size_12_White)
			]
			+SHorizontalBox::Slot()
			.FillWidth(1)
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("查看")))
					.Font(MainStyle->FontInfo_Size_12_Blue)
				]
				+SOverlay::Slot()
				[
					SAssignNew(Item_Button,SButton)
					.OnClicked(this,&SInRoomRightBttomWidgetItem3Item::Item_Button_OnClick)
					.ButtonStyle(&MainStyle->ButtonStyle_Item_Chakan)
				]
			]
		]
	];
	
}

FReply SInRoomRightBttomWidgetItem3Item::Item_Button_OnClick()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.0,FColor::Yellow,FString("查看"));
	}
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
