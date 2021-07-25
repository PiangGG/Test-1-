// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SLeftTopButtonWidget.h"
#include "SlateOptMacros.h"
#include "GamePlay/MainGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Style/LFSStyle.h"
#include "UI/Style/MainSlateWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLeftTopButtonWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.Padding(FMargin(10,5,10,5))
			[
				SAssignNew(TextBlock,STextBlock)
				.Font(MainStyle->FontInfo_Size_16_Blue)
				.Text(FText::FromString(TEXT("切换")))
				//.TextStyle(&MainStyle->LeftTopButtonTextStyle)
			]
			+SOverlay::Slot()
			[
				SNew(SButton)
				.ButtonStyle(&MainStyle->ButtonStyle_DMY)
				.OnClicked(this,&SLeftTopButtonWidget::OnButtonOnclick)
			]
		]
	];
	
}

FReply SLeftTopButtonWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	
	return FReply::Handled();
}

FReply SLeftTopButtonWidget::OnButtonOnclick()
{
	UE_LOG(LogTemp,Warning,TEXT("OnButtonOnclick"));
	switch (ButtonStyle)
	{
		case EButtonStyle::Swtich:
			Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->ChangeWorldMode(EWorldMode::Mode2);
			ShowText=FText::FromString(TEXT("还原"));
			TextBlock->SetText(ShowText);
			ButtonStyle=EButtonStyle::Reset;
			break;
		case EButtonStyle::Reset:
			Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->ChangeWorldMode(EWorldMode::Mode1);
			ShowText=FText::FromString(TEXT("切换"));
			TextBlock->SetText(ShowText);
			ButtonStyle=EButtonStyle::Swtich;
			break;
		case EButtonStyle::Back:
			Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->ChangeActorLocation(FString("Start"));
			ShowText=FText::FromString(TEXT("返回"));
			TextBlock->SetText(ShowText);
			ButtonStyle=EButtonStyle::Back;
			break;
		default: break;
	}
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
