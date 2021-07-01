// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SMainWidget.h"
#include "SlateOptMacros.h"
#include "UI/Widget/SMainBottomWidget.h"
#include "UI/Widget/SMainCenterWidget.h"
#include "UI/Widget/SMainLeftWidget.h"
#include "UI/Widget/SMainRightWidget.h"
#include "UI/Widget/SMainTopWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SOverlay)
			+SOverlay::Slot()//Left
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
			]
			+SOverlay::Slot()//Right
			[
				SAssignNew(MainRightWidget,SMainRightWidget)
			]
			
			+SOverlay::Slot()//Bottom
			[
				SAssignNew(MainBottomWidget,SMainBottomWidget)
			]
			+SOverlay::Slot()
			[
				SAssignNew(MainCenterWidget,SMainCenterWidget)
			]//center
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
