// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TongDao/STodaoMainWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Widget/Main/SMainTopWidget.h"
#include "UI/Widget/TongDao/Left/SLeft_Main.h"
#include "UI/Widget/Tongdao/Right/SRight_Main.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STodaoMainWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+SOverlay::Slot()
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Fill)
		[
			SNew(SMainTopWidget)
		]
		+SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Left)
		[
			SAssignNew(Left_Main,SLeft_Main)
		]
		+SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Right)
		.Padding(0,0,5,0)
		[
			SAssignNew(Right_Main,SRight_Main)
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
