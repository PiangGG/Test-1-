// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Widget/Main/Right/SMainRightWidget.h"

#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/Main/Right/SMainRight_Buttom.h"
#include "UI/Widget/Main/Right/SMainRight_Center.h"
#include "UI/Widget/Main/Right/SMainRight_Top.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainRightWidget::Construct(const FArguments& InArgs)
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
				SNew(SImage)
				.Image(&MainStyle->Main_Right_BG)
			]
			+SOverlay::Slot()
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.AutoHeight()
				[
					SAssignNew(MainRight_Top,SMainRight_Top)
				]
				+SVerticalBox::Slot()
				.AutoHeight()
				[
					SAssignNew(MainRight_Center,SMainRight_Center)
				]
				+SVerticalBox::Slot()
				.AutoHeight()
				.VAlign(VAlign_Bottom)
				[
					SAssignNew(MainRight_Buttom,SMainRight_Buttom)
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
