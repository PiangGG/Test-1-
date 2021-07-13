// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Widget/Main/Left/SMain_Left_State_Widget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Notifications/SProgressBar.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMain_Left_State_Widget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	
	StateImageIcon = InArgs._StateImageIcon.Get();
	ShowText=InArgs._ShowText.Get();
	ProgressBarText=InArgs._ProgressBarText.Get();
	ProbarSize=InArgs._ProbarSize.Get();
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
					[
						SNew(SImage)
						.Image(&StateImageIcon)
					]
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
					.Padding(FMargin(0,0,0,0))
					[
						SNew(STextBlock)
						.Text(FText::FromString(ShowText))
						.Font(MainStyle->FontInfo_Size_16_White)
						.MinDesiredWidth(120.0f)
					]
				]
				+SVerticalBox::Slot()
				.Padding(FMargin(0,10,0,0))
				[
					SNew(SBox)
					.HeightOverride(8.f)
					[
						SNew(SBorder)
						.ContentScale(FVector2D(1.0f,1.0f))
						[
							SNew(SOverlay)
							+SOverlay::Slot()		
							[	
								SAssignNew(ProgressBar,SProgressBar)
								.Percent(ProbarSize)
								.BackgroundImage(&MainStyle->ProbarBGBrush)
								.FillImage(&MainStyle->ProbarFillImageBrush)
							]
							+SOverlay::Slot()
							.HAlign(HAlign_Left)
							.VAlign(VAlign_Center)
							.Padding(FMargin(20,0,0,0))
							[
								SNew(STextBlock)
								.Text(FText::FromString(ProgressBarText))
								.Font(MainStyle->FontInfo_Size_12_White)
							]
						]
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
