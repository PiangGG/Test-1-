// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MainHUD.h"
#include "UI/Widget/Mian/SMainWidget.h"

AMainHUD::AMainHUD()
{
	if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(MainWidget, SMainWidget);
		GEngine->GameViewport->AddViewportWidgetContent(MainWidget.ToSharedRef());
		UE_LOG(LogTemp,Warning,TEXT("InitAElMenuHUD"));
	}
}
