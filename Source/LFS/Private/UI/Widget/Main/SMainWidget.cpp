// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Widget/Main/SMainWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Widget/Main/SMainCenterWidget.h"
#include "UI/Widget/Main/SMainTopWidget.h"
#include "UI/Widget/Main/Buttom/SMainBottomWidget.h"
#include "UI/Widget/Main/Left/SMainLeftWidget.h"
#include "UI/Widget/Main/Right/SMainRightWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	
	ChildSlot
	[
		// Populate the widget
		//SNew(SBox)
		/*.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)*/
		//[
			SNew(SOverlay)
			+SOverlay::Slot()//Left
			.Padding(FMargin(0,30,0,0))
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			[
				SAssignNew(MainLeftWidget,SMainLeftWidget)
			]
			+SOverlay::Slot()//Top
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Top)
			[
				SAssignNew(MainTopWidget,SMainTopWidget)
				.bShowButton(false)
			]
			+SOverlay::Slot()//Right
			.Padding(FMargin(0,30,0,0))
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			[
				SAssignNew(MainRightWidget,SMainRightWidget)
			]
			
			+SOverlay::Slot()//Bottom
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Bottom)
			[
				SAssignNew(MainBottomWidget,SMainBottomWidget)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SAssignNew(MainCenterWidget,SMainCenterWidget)
			]//center
		//]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
