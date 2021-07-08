// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/SMainTopWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainTopWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		//.HeightOverride(800)
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Fill)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SNew(SImage)
				.Image(&MainStyle->Main_Top_BG)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("市区公司配电网孪生系统")))
				.Font(MainStyle->FontInfo_Size_16_White)
			]
		]	
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
