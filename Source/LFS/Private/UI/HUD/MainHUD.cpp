// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MainHUD.h"

#include "UI/Widget/Main/SMainWidget.h"
#include "UI/Widget/TongDao/STodaoMainWidget.h"

AMainHUD::AMainHUD()
{
	/*if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(MainWidget, SMainWidget);
		GEngine->GameViewport->AddViewportWidgetContent(MainWidget.ToSharedRef());
		UE_LOG(LogTemp,Warning,TEXT("InitAElMenuHUD"));
	}
	if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(TodaoMainWidget, STodaoMainWidget);
		GEngine->GameViewport->AddViewportWidgetContent(TodaoMainWidget.ToSharedRef());
		UE_LOG(LogTemp,Warning,TEXT("InitAElMenuHUD"));
	}*/
}

void AMainHUD::ChangeHUDState(HUDStateEnum newState)
{
	switch (newState)
	{
	case Null:
		if (GEngine&&GEngine->GameViewport)
		{
			GEngine->GameViewport->RemoveAllViewportWidgets();
		}
		break;
	case Main:
		if (GEngine&&GEngine->GameViewport)
		{
			GEngine->GameViewport->RemoveAllViewportWidgets();
			SAssignNew(MainWidget, SMainWidget);
			GEngine->GameViewport->AddViewportWidgetContent(MainWidget.ToSharedRef());
		}
		break;
	case TongDao:
		if (GEngine&&GEngine->GameViewport)
		{
			GEngine->GameViewport->RemoveAllViewportWidgets();
			SAssignNew(TodaoMainWidget, STodaoMainWidget);
			GEngine->GameViewport->AddViewportWidgetContent(TodaoMainWidget.ToSharedRef());
		}
		break;
	default: ;
	}
}

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();
	ChangeHUDState(HUDStateEnum::Null);
}
