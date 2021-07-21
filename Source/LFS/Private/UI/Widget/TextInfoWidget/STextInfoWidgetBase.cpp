// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TextInfoWidget/STextInfoWidgetBase.h"
#include "SlateOptMacros.h"
#include "GamePlay/MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/Images/SImage.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "GamePlay/MainGameMode.h"
#include "Widgets/SViewport.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STextInfoWidgetBase::Construct(const FArguments& InArgs)
{
	TextImage=InArgs._TextImage.Get();
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		[
			SNew(SBorder)
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				[
					SNew(SImage)
					.Image(&TextImage)
					.OnMouseButtonDown(this,&STextInfoWidgetBase::OnMouseButtonDown)
				]
			]
		]
	];
	
}

FReply STextInfoWidgetBase::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	/*UE_LOG(LogTemp,Warning,TEXT("STextInfoWidgetBase::OnMouseButtonUp"));

	if (LocationActor&&UGameplayStatics::GetPlayerController(GWorld,0))
	{
		UE_LOG(LogTemp,Warning,TEXT("STextInfoWidgetBase::OnMouseButtonUp1"));
		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->SpawnCharatorClass=AMainCharacter::StaticClass();
		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->JumpActorLocation(LocationActor);
		LocationActor->SetActorHiddenInGame(true);
	}
	*/
	return FReply::Handled();
}

FReply STextInfoWidgetBase::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	
	UE_LOG(LogTemp,Warning,TEXT("STextInfoWidgetBase::OnMouseButtonDown"));
	if (LocationActor&&UGameplayStatics::GetPlayerController(GWorld,0))
	{
		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->SpawnCharatorClass=AMainCharacter::StaticClass();
		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->JumpActorLocation(LocationActor);
		LocationActor->SetActorHiddenInGame(true);
	}
	
	return FReply::Handled();
}

void STextInfoWidgetBase::SetLocationActor(AActor* Actor)
{
	LocationActor=Actor;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
