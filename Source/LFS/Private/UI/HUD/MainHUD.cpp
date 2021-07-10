// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MainHUD.h"

#include "UI/Widget/ActorObjectInfo/SActorObjectInfoMainWidget.h"
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

void AMainHUD::ChangeHUDState(HUDStateEnum newState)
{
	switch (newState)
	{
	case NullState:
		if (GEngine&&GEngine->GameViewport)
		{
			GEngine->GameViewport->RemoveAllViewportWidgets();
		}
		break;
	case MainState:
		if (GEngine&&GEngine->GameViewport)
		{
			GEngine->GameViewport->RemoveAllViewportWidgets();
			SAssignNew(MainWidget, SMainWidget);
			GEngine->GameViewport->AddViewportWidgetContent(MainWidget.ToSharedRef());
		}
		break;
	case TongDaoState:
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
	ChangeHUDState(HUDStateEnum::NullState);
}

void AMainHUD::ShowInfoWidget()
{
	if (GEngine&&GEngine->GameViewport)
	{
		if (InfoWidget)
		{
			GEngine->GameViewport->RemoveViewportWidgetContent(InfoWidget.ToSharedRef());
			SAssignNew(InfoWidget, SActorObjectInfoMainWidget);
			GEngine->GameViewport->AddViewportWidgetContent(InfoWidget.ToSharedRef());
		}else
		{
			SAssignNew(InfoWidget, SActorObjectInfoMainWidget);
			GEngine->GameViewport->AddViewportWidgetContent(InfoWidget.ToSharedRef());
		}
		
	}
}

void AMainHUD::HideInfoWidget()
{
	if (GEngine&&GEngine->GameViewport&&InfoWidget)
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(InfoWidget.ToSharedRef());
	}
}
