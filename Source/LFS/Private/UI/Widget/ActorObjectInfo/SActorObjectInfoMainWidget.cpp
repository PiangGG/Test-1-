// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/ActorObjectInfo/SActorObjectInfoMainWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"
#include "UI/Widget/ActorObjectInfo/SDLGZWidget.h"
#include "UI/Widget/ActorObjectInfo/SDLXXWidget.h"
#include "UI/Widget/ActorObjectInfo/SYXSJWidget.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SActorObjectInfoMainWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");

	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SAssignNew(Overlay,SOverlay)
			+SOverlay::Slot()
			.Padding(700,200,700,0)
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
						.HAlign(HAlign_Fill)
						[
							SNew(SOverlay)
							+SOverlay::Slot()
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Font(MainStyle->FontInfo_Size_16_White)
								.Text(FText::FromString(TEXT("电缆信息")))
							]
							+SOverlay::Slot()
							[	
								SAssignNew(Button_DLXX,SButton)
								.ButtonStyle(&MainStyle->SelecdButtonStyle)
								.OnClicked(this,&SActorObjectInfoMainWidget::BuuttonOnClick_1)
							]
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Fill)
						[
							SNew(SOverlay)
							+SOverlay::Slot()
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Font(MainStyle->FontInfo_Size_16_White)
								.Text(FText::FromString(TEXT("电缆信息")))
							]
							+SOverlay::Slot()
							[
								SAssignNew(Button_DLXX,SButton)
								.ButtonStyle(&MainStyle->SelecdButtonStyle)
								.OnClicked(this,&SActorObjectInfoMainWidget::BuuttonOnClick_2)
							]
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Fill)
						[
							SNew(SOverlay)
							+SOverlay::Slot()
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Font(MainStyle->FontInfo_Size_16_White)
								.Text(FText::FromString(TEXT("运行数据")))
							]
							+SOverlay::Slot()
							[
								SAssignNew(Button_DLXX,SButton)
								.ButtonStyle(&MainStyle->SelecdButtonStyle)
								.OnClicked(this,&SActorObjectInfoMainWidget::BuuttonOnClick_3)
							]
							
						]
						+SHorizontalBox::Slot()
						.HAlign(HAlign_Fill)
						[
							SNew(SOverlay)
							+SOverlay::Slot()
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Font(MainStyle->FontInfo_Size_16_White)
								.Text(FText::FromString(TEXT("电缆感知")))
							]
							+SOverlay::Slot()
							[
								SAssignNew(Button_DLXX,SButton)
								.ButtonStyle(&MainStyle->SelecdButtonStyle)
								.OnClicked(this,&SActorObjectInfoMainWidget::BuuttonOnClick_4)
							]
						]
					]	
				]
				+SVerticalBox::Slot()
				.AutoHeight()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				[
					SNew(SBox)
					[
						SNew(SOverlay)
						+SOverlay::Slot()
						[
							SNew(SBorder)
							[
								SAssignNew(Content,SOverlay)
							]
						]
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
