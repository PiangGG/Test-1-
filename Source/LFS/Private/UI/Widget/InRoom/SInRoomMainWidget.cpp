// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomMainWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Widget/InRoom/SInRoomLeftButtomWidget.h"
#include "UI/Widget/InRoom/SInRoomLeftButtom_HJJCWidget.h"
#include "UI/Widget/InRoom/SInRoomLeftTopWidget.h"
#include "UI/Widget/InRoom/SInRoomRightBttomWidget.h"
#include "UI/Widget/InRoom/SInRoomRightTopWidget.h"
#include "UI/Widget/Main/SMainTopWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomMainWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Top)
			[
				SAssignNew(MainTopWidget,SMainTopWidget)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Top)
			.Padding(0,70,0,0)
			[
				SAssignNew(InRoomLeftTopWidget,SInRoomLeftTopWidget)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Bottom)
			.Padding(0,0,0,60)
			[
				SAssignNew(InRoomLeftButtom_HJJCWidget,SInRoomLeftButtom_HJJCWidget)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Top)
			.Padding(0,70,0,0)
			[
				SAssignNew(InRoomRightTopWidget,SInRoomRightTopWidget)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Bottom)
			.Padding(0,0,0,60)
			[
				SAssignNew(InRoomRightBttomWidget,SInRoomRightBttomWidget)
			]
			//底部按钮标签
			+SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Bottom)
			.Padding(0,0,0,0)
			[
				SAssignNew(InRoomLeftButtomWidget,SInRoomLeftButtomWidget)
			]
			
		]
	];
	
}

void SInRoomMainWidget::ShowHHJCWidget()
{
	
	if (InRoomLeftButtom_HJJCWidget)
	{
		InRoomLeftButtom_HJJCWidget->SetVisibility(EVisibility::Visible);
		UE_LOG(LogTemp,Warning,TEXT("ShowHHJCWidget"));
	}
}

void SInRoomMainWidget::HideHJJCWidget()
{
	if (InRoomLeftButtom_HJJCWidget)
	{
		InRoomLeftButtom_HJJCWidget->SetVisibility(EVisibility::Hidden);
		UE_LOG(LogTemp,Warning,TEXT("HideHJJCWidget"));
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
