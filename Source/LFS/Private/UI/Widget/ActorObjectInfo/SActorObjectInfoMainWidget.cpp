// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ActorObjectInfo/SActorObjectInfoMainWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/ActorObjectInfo/SDLXXWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SActorObjectInfoMainWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+SOverlay::Slot()
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					[
						SAssignNew(Button_DLXX,SButton)
						.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
						.Text(FText::FromString(TEXT("电缆信息")))
						//.OnClicked()
					]
					+SHorizontalBox::Slot()
					[
						SAssignNew(Button_DLXX,SButton)
						.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
						.Text(FText::FromString(TEXT("台账信息")))
					]
					+SHorizontalBox::Slot()
					[
						SAssignNew(Button_DLXX,SButton)
						.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
						.Text(FText::FromString(TEXT("运行数据")))
					]
					+SHorizontalBox::Slot()
					[
						SAssignNew(Button_DLXX,SButton)
						.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
						.Text(FText::FromString(TEXT("电缆感知")))
					]
				]	
			]
			+SVerticalBox::Slot()
			[
				SNew(SBox)
				[
					SNew(SOverlay)
					+SOverlay::Slot()
					[
						SAssignNew(DLXXWidget,SDLXXWidget)
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
