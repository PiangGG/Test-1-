// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/InRoom/SInRoomLeftButtomWidget.h"
#include "SlateOptMacros.h"
#include "GamePlay/MainGameMode.h"
#include "GamePlay/MainMenuController.h"
#include "Kismet/GameplayStatics.h"
#include "Object/ItemObject/WorkObjectActor.h"
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
				.AutoHeight()
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
						SNew(SOverlay)
						/*+SOverlay::Slot()
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
						]*/
						+SOverlay::Slot()
						[	
							SAssignNew(HJJC_Button,SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ButtonStyle(&MainStyle->SelecdButtonStyle)
							.Text(FText::FromString(TEXT("电缆信息")))
							.TextStyle(&MainStyle->TextBlockStyle)
							.OnClicked(this,&SInRoomLeftButtomWidget::BuuttonOnClick_1)
						]
					]
					+SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SOverlay)
						/*+SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							
						]*/
						+SOverlay::Slot()
						[	
							SAssignNew(GJXX_Button,SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ButtonStyle(&MainStyle->SelecdButtonStyle)
							.OnClicked(this,&SInRoomLeftButtomWidget::BuuttonOnClick_2)
							.Text(FText::FromString(TEXT("告警信息")))
							.TextStyle(&MainStyle->TextBlockStyle)
						]
					]
					+SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SOverlay)
						/*+SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("智能巡检")))
						]*/
						+SOverlay::Slot()
						[	
							SAssignNew(ZNXJ_Button,SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ButtonStyle(&MainStyle->SelecdButtonStyle)
							.OnClicked(this,&SInRoomLeftButtomWidget::BuuttonOnClick_3)
							.Text(FText::FromString(TEXT("智能巡检")))
							.TextStyle(&MainStyle->TextBlockStyle)
						]
					]
					+SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SOverlay)
						/*+SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MainStyle->FontInfo_Size_16_White)
							.Text(FText::FromString(TEXT("作业管控")))
						]*/
						+SOverlay::Slot()
						[	
							SAssignNew(ZYGK_Button,SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ButtonStyle(&MainStyle->SelecdButtonStyle)
							.OnClicked(this,&SInRoomLeftButtomWidget::BuuttonOnClick_4)
							.Text(FText::FromString(TEXT("作业管控")))
							.TextStyle(&MainStyle->TextBlockStyle)
						]
					]
				]				
			]
		]
	];
	if (InRoomRightBttomWidget_Item_4&&GWorld)
	{
		UGameplayStatics::GetAllActorsOfClass(GWorld,AWorkObjectActor::StaticClass(),ArrayActors);
		for (int i=0;i<ArrayActors.Num();i++)
		{
			Cast<AWorkObjectActor>(ArrayActors[i])->OnMouseButton_Left_OnClick();
		}
	}else
	{
		UGameplayStatics::GetAllActorsOfClass(GWorld,AWorkObjectActor::StaticClass(),ArrayActors);
		for (int i=0;i<ArrayActors.Num();i++)
		{
			Cast<AWorkObjectActor>(ArrayActors[i])->ChangeActorState(EWorkObjectActorState::Null);
		}
	}
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
	//if (Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->RobotActorObject==nullptr)
	{
		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->CreateCat();
	}
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
	Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->ShowAllWorkObject();
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
