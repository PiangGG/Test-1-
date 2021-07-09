// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SLFSProgressbar.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "Widgets/Notifications/SProgressBar.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLFSProgressbar::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	percent=InArgs._percent.Get();
	Name=InArgs._Name.Get();
	Number=FString::SanitizeFloat(percent*100)+FString("%");
	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		
		+SOverlay::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Left)
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_12_White)
				.Text(FText::FromString(Name))
			]
			+SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Right)
			[
				SNew(STextBlock)
				.Font(MainStyle->FontInfo_Size_12_White)
				.Text(FText::FromString(Number))
			]
		]
		+SOverlay::Slot()
		[
			SAssignNew(ProgressBar,SProgressBar)
			.Percent(percent)
			.BackgroundImage(&MainStyle->ProbarBGBrush)
			.FillImage(&MainStyle->ProbarFillImageBrush)
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
