// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ActorObjectInfo/SInfoButtonWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInfoButtonWidget::Construct(const FArguments& InArgs)
{
	//MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	
	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+SOverlay::Slot()
		[
			SNew(SButton)
			//.ButtonStyle(ButtonStyle)
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
