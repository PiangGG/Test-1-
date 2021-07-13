// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ActorObjectInfo/SActorObjectInfoMainWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/ActorObjectInfo/SDLGZWidget.h"
#include "UI/Widget/ActorObjectInfo/SDLXXWidget.h"
#include "UI/Widget/ActorObjectInfo/SYXSJWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SActorObjectInfoMainWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");

	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.Padding(300,300,500,300)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.AutoHeight()
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
							.OnClicked(this,&SActorObjectInfoMainWidget::BuuttonOnClick_1)
						]
						+SHorizontalBox::Slot()
						[
							SAssignNew(Button_DLXX,SButton)
							.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
							.Text(FText::FromString(TEXT("台账信息")))
							.OnClicked(this,&SActorObjectInfoMainWidget::BuuttonOnClick_2)
						]
						+SHorizontalBox::Slot()
						[
							SAssignNew(Button_DLXX,SButton)
							.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
							.Text(FText::FromString(TEXT("运行数据")))
							.OnClicked(this,&SActorObjectInfoMainWidget::BuuttonOnClick_3)
						]
						+SHorizontalBox::Slot()
						[
							SAssignNew(Button_DLXX,SButton)
							.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
							.Text(FText::FromString(TEXT("电缆感知")))
							.OnClicked(this,&SActorObjectInfoMainWidget::BuuttonOnClick_4)
						]
					]	
				]
				+SVerticalBox::Slot()
				[
					SNew(SBox)
					.WidthOverride(600.f)
					.HeightOverride(800.f)
					[
						SAssignNew(Content,SOverlay)
						
					]
				]
			]
		]
	];
	BuuttonOnClick_1();
}

FReply SActorObjectInfoMainWidget::BuuttonOnClick_1()
{
	Content->ClearChildren();
	Content->AddSlot()
	[
		SAssignNew(DLXXWidget,SDLXXWidget)
	];
	
	return FReply::Handled();
}
FReply SActorObjectInfoMainWidget::BuuttonOnClick_2()
{
	Content->ClearChildren();
	/*Content->AddSlot()
	[
		SAssignNew(DLXXWidget,SDLXXWidget)
	];*/
	return FReply::Handled();
}

FReply SActorObjectInfoMainWidget::BuuttonOnClick_3()
{
	Content->ClearChildren();
	Content->AddSlot()
	[
		SAssignNew(YXSJWidget,SYXSJWidget)
	];
	return FReply::Handled();
}

FReply SActorObjectInfoMainWidget::BuuttonOnClick_4()
{
	Content->ClearChildren();
	Content->AddSlot()
	[
		SAssignNew(DLGZWidget,SDLGZWidget)
	];
	return FReply::Handled();
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
