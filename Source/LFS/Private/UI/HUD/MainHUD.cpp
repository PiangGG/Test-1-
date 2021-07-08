// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MainHUD.h"

#include "UI/Widget/Main/SMainWidget.h"
#include "UI/Widget/TongDao/STodaoMainWidget.h"

AMainHUD::AMainHUD()
{
	if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(MainWidget, SMainWidget);
		GEngine->GameViewport->AddViewportWidgetContent(MainWidget.ToSharedRef());
		UE_LOG(LogTemp,Warning,TEXT("InitAElMenuHUD"));
	}
	/*if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(TodaoMainWidget, STodaoMainWidget);
		GEngine->GameViewport->AddViewportWidgetContent(TodaoMainWidget.ToSharedRef());
		UE_LOG(LogTemp,Warning,TEXT("InitAElMenuHUD"));
	}*/
}
