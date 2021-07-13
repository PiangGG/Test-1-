// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomLeftButtomWidget.h"
#include "SlateOptMacros.h"
#include "GamePlay/MainMenuController.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/MainHUD.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/InRoom/SInRoomMainWidget.h"
#include "UI/Widget/InRoom/SInRoomRightBttomWidget_Item_1.h"
#include "UI/Widget/InRoom/SInRoomRightBttomWidget_Item_2.h"
#include "UI/Widget/InRoom/SInRoomRightBttomWidget_Item_3.h"
#include "UI/Widget/InRoom/SInRoomRightBttomWidget_Item_4.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInRoomLeftButtomWidget::Construct(const FArguments& InArgs)
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
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				[
					SAssignNew(Content,SOverlay)
				]
				+SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.AutoWidth()
					[
						SAssignNew(HJJC_Button,SButton)
						.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
						.Text(FText::FromString(TEXT("环境监测")))
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
						.OnClicked(this,&SInRoomLeftButtomWidget::BuuttonOnClick_1)
					]
					+SHorizontalBox::Slot()
					[
						SAssignNew(GJXX_Button,SButton)
						.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
						.Text(FText::FromString(TEXT("告警信息")))
						.OnClicked(this,&SInRoomLeftButtomWidget::BuuttonOnClick_2)
					]
					+SHorizontalBox::Slot()
					[
						SAssignNew(ZNXJ_Button,SButton)
						.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
						.Text(FText::FromString(TEXT("智能巡检")))
						.OnClicked(this,&SInRoomLeftButtomWidget::BuuttonOnClick_3)
					]
					+SHorizontalBox::Slot()
					[
						SAssignNew(ZYGK_Button,SButton)
						.ButtonStyle(&MainStyle->NotSelecdButtonStyle)
						.Text(FText::FromString(TEXT("作业管控")))
						.OnClicked(this,&SInRoomLeftButtomWidget::BuuttonOnClick_4)
					]
				]				
			]
		]
	];
	
}

FReply SInRoomLeftButtomWidget::BuuttonOnClick_1()
{
	Content->ClearChildren();
	HideHJJCWidget();
	if (InRoomRightBttomWidget_Item_1.IsValid())
	{
		ShowHJJCWidegt();
		InRoomRightBttomWidget_Item_1=nullptr;
		return FReply::Handled();
	}
	Content->AddSlot()
	[
		SAssignNew(InRoomRightBttomWidget_Item_1,SInRoomRightBttomWidget_Item_1)
	];
	return FReply::Handled();
}

FReply SInRoomLeftButtomWidget::BuuttonOnClick_2()
{
	Content->ClearChildren();
	HideHJJCWidget();
	if (InRoomRightBttomWidget_Item_2.IsValid())
	{
		ShowHJJCWidegt();
		InRoomRightBttomWidget_Item_2=nullptr;
		return FReply::Handled();
	}
	Content->AddSlot()
	[
		SAssignNew(InRoomRightBttomWidget_Item_2,SInRoomRightBttomWidget_Item_2)
	];
	return FReply::Handled();
}

FReply SInRoomLeftButtomWidget::BuuttonOnClick_3()
{
	Content->ClearChildren();
	HideHJJCWidget();
	if (InRoomRightBttomWidget_Item_3.IsValid())
	{
		ShowHJJCWidegt();
		InRoomRightBttomWidget_Item_3=nullptr;
		return FReply::Handled();
	}
	Content->AddSlot()
	[
		SAssignNew(InRoomRightBttomWidget_Item_3,SInRoomRightBttomWidget_Item_3)
	];
	return FReply::Handled();
}

FReply SInRoomLeftButtomWidget::BuuttonOnClick_4()
{
	Content->ClearChildren();
	HideHJJCWidget();
	if (InRoomRightBttomWidget_Item_4.IsValid())
	{
		ShowHJJCWidegt();
		InRoomRightBttomWidget_Item_4=nullptr;
		return FReply::Handled();
	}
	Content->AddSlot()
	[
		SAssignNew(InRoomRightBttomWidget_Item_4,SInRoomRightBttomWidget_Item_4)
	];
	return FReply::Handled();
}

void SInRoomLeftButtomWidget::ShowHJJCWidegt()
{
	AMainMenuController *Controller =Cast<AMainMenuController>(GWorld->GetFirstPlayerController());
	if (!Controller)return;
	AMainHUD* MainHUD=Cast<AMainHUD>(Controller->GetHUD());
	if (MainHUD&&MainHUD->InRoomMainWidget)
	{
		UE_LOG(LogTemp,Warning,TEXT("ShowHHJCWidget"));
		MainHUD->InRoomMainWidget->ShowHHJCWidget();
	}
}

void SInRoomLeftButtomWidget::HideHJJCWidget()
{
	AMainMenuController *Controller =Cast<AMainMenuController>(GWorld->GetFirstPlayerController());
	if (!Controller)return;
	AMainHUD* MainHUD=Cast<AMainHUD>(Controller->GetHUD());
	if (MainHUD&&MainHUD->InRoomMainWidget)
	{
		UE_LOG(LogTemp,Warning,TEXT("HideHJJCWidget"));	
		MainHUD->InRoomMainWidget->HideHJJCWidget();
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
