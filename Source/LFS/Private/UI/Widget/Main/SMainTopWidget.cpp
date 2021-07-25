// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/Main/SMainTopWidget.h"
#include "SlateOptMacros.h"
#include "GamePlay/MainGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/MainHUD.h"
#include "UI/Widget/SLeftTopButtonWidget.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainTopWidget::Construct(const FArguments& InArgs)
{
	MainStyle=&LFSStyle::Get().GetWidgetStyle<FMainSlateStyle>("BPMainStyle");
	bShowButton=InArgs._bShowButton.Get();
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
				.Font(MainStyle->FontInfo_Size_36_White)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(FMargin(5,0,0,0))
			[
				SAssignNew(LeftTopButtonWidget,SLeftTopButtonWidget)
			]
		]	
	];
}

FReply SMainTopWidget::BackMainMap()
{
	if (GWorld)
	{
		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->ChangeActorLocation(FString("Start"));
	}
	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
