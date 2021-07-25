// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MainHUD.h"

#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Object/TextObject/TextObjectActor.h"
#include "UI/Widget/ActorObjectInfo/SActorObjectInfoMainWidget.h"
#include "UI/Widget/ActorObjectInfo/DCMK/SDCMKMainWidget.h"
#include "UI/Widget/InRoom/SInRoomMainWidget.h"
#include "UI/Widget/Main/SMainTopWidget.h"
#include "UI/Widget/Main/SMainWidget.h"
#include "UI/Widget/TongDao/STDGZWidget.h"
#include "UI/Widget/TongDao/STodaoMainWidget.h"
#include "SlateBasics.h"
#include "GamePlay/MainGameMode.h"
#include "UI/Widget/ActorObjectInfo/SMoitorJKWidget.h"

AMainHUD::AMainHUD()
{
	
}

void AMainHUD::ChangeHUDState(HUDStateEnum newState)
{
	CurrentState=newState;
	switch (newState)
	{
	case HUDStateEnum::NullState:
		ChangeHUDState_NullState();
		break;
	case HUDStateEnum::MainState:
		ChangeHUDState_MainState();
		break;
	case HUDStateEnum::TongDaoState:
		ChangeHUDState_TongDaoState();
		break;
	case HUDStateEnum::TDGZState:
			//SAssignNew(TDGZWidget, STDGZWidget);
			//GEngine->GameViewport->AddViewportWidgetContent(TDGZWidget.ToSharedRef(),-50);
			break;
	case HUDStateEnum::InRoomState:
		ChangeHUDState_InRoomState();
		break;
	default:
		break;
	}
	
}

void AMainHUD::ChangeHUDState_NullState()
{
	if (GEngine&&GEngine->GameViewport&&MainWidget.IsValid())
	{
		
		MainWidget->SetVisibility(EVisibility::Visible);
		TodaoMainWidget->SetVisibility(EVisibility::Hidden);
		InRoomMainWidget->SetVisibility(EVisibility::Hidden);
		
		MainWidget->ChangeShowMenu(false);
		HideAllLocationObjectTextWidget();
	}
}

void AMainHUD::ChangeHUDState_MainState()
{
	if (GEngine&&GEngine->GameViewport&&MainWidget.IsValid())
	{
		MainWidget->SetVisibility(EVisibility::Visible);
		TodaoMainWidget->SetVisibility(EVisibility::Hidden);
		InRoomMainWidget->SetVisibility(EVisibility::Hidden);
		
		MainWidget->ChangeShowMenu(true);
		ShowAllLocationObjectTextWidget();
	}
}

void AMainHUD::ChangeHUDState_TongDaoState()
{
	if (GEngine&&GEngine->GameViewport&&TodaoMainWidget.IsValid())
	{
		MainWidget->SetVisibility(EVisibility::Hidden);
		
		TodaoMainWidget->SetVisibility(EVisibility::Visible);
		//TodaoMainWidget
		
		InRoomMainWidget->SetVisibility(EVisibility::Hidden);
		HideAllLocationObjectTextWidget();

		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->ChangeWorldMode(EWorldMode::Mode1);
	}
}

void AMainHUD::ChangeHUDState_InRoomState()
{
	if (GEngine&&GEngine->GameViewport&&InRoomMainWidget.IsValid())
	{
		MainWidget->SetVisibility(EVisibility::Hidden);
		TodaoMainWidget->SetVisibility(EVisibility::Hidden);
		InRoomMainWidget->SetVisibility(EVisibility::Visible);
		HideAllLocationObjectTextWidget();
		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->ChangeWorldMode(EWorldMode::Mode2);
	}
}

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	SAssignNew(MainWidget, SMainWidget);
	SAssignNew(TodaoMainWidget, STodaoMainWidget);
	SAssignNew(InRoomMainWidget, SInRoomMainWidget);
	
	if (GEngine->GameViewport)
	{
		GEngine->GameViewport->AddViewportWidgetContent(MainWidget.ToSharedRef(),-50);
		MainWidget->ChangeShowMenu(false);
		MainWidget->SetVisibility(EVisibility::Visible);
		
		GEngine->GameViewport->AddViewportWidgetContent(TodaoMainWidget.ToSharedRef(),-50);
		TodaoMainWidget->SetVisibility(EVisibility::Hidden);

		GEngine->GameViewport->AddViewportWidgetContent(InRoomMainWidget.ToSharedRef(),-50);
		InRoomMainWidget->SetVisibility(EVisibility::Hidden);
	}
	HideAllLocationObjectTextWidget();
	/*if (true)
	{
		
	}*/
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

void AMainHUD::ShowCableInfoWidget()
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

void AMainHUD::ShowBatteryModuleInfoWidget()
{
	if (GEngine&&GEngine->GameViewport)
	{
		if (InfoWidget)
		{
			GEngine->GameViewport->RemoveViewportWidgetContent(InfoWidget.ToSharedRef());
			SAssignNew(InfoWidget, SDCMKMainWidget);
			GEngine->GameViewport->AddViewportWidgetContent(InfoWidget.ToSharedRef());
		}else
		{
			SAssignNew(InfoWidget, SDCMKMainWidget);
			GEngine->GameViewport->AddViewportWidgetContent(InfoWidget.ToSharedRef());
		}
		
	}
}

void AMainHUD::ShowMonitorInfoWidget()
{
	if (GEngine&&GEngine->GameViewport)
	{
		if (InfoWidget)
		{
			GEngine->GameViewport->RemoveViewportWidgetContent(InfoWidget.ToSharedRef());
			SAssignNew(InfoWidget, STDGZWidget);
			GEngine->GameViewport->AddViewportWidgetContent(InfoWidget.ToSharedRef());
		}else
		{
			SAssignNew(InfoWidget, STDGZWidget);
			GEngine->GameViewport->AddViewportWidgetContent(InfoWidget.ToSharedRef());
		}
		
	}
}
void AMainHUD::ShowMonitor2InfoWidget()
{
	if (GEngine&&GEngine->GameViewport)
	{
		if (InfoWidget)
		{
			GEngine->GameViewport->RemoveViewportWidgetContent(InfoWidget.ToSharedRef());
			SAssignNew(InfoWidget, SMoitorJKWidget);
			GEngine->GameViewport->AddViewportWidgetContent(InfoWidget.ToSharedRef());
		}else
		{
			SAssignNew(InfoWidget, SMoitorJKWidget);
			GEngine->GameViewport->AddViewportWidgetContent(InfoWidget.ToSharedRef());
		}
		
	}
}
void AMainHUD::ShowAllLocationObjectTextWidget()
{
	if (GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(),ATextObjectActor::StaticClass(),TextObjectActor);
		for (int i=0;i<TextObjectActor.Num();i++)
		{
			Cast<ATextObjectActor>(TextObjectActor[i])->ShowWidget();
		}
	}
	
}

void AMainHUD::HideAllLocationObjectTextWidget()
{
	if (GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(),ATextObjectActor::StaticClass(),TextObjectActor);
		for (int i=0;i<TextObjectActor.Num();i++)
		{
			Cast<ATextObjectActor>(TextObjectActor[i])->HideWidget();
		}
	}
}

void AMainHUD::ShowAllUI()
{
	if (GEngine&&GEngine->GameViewport)
	{
		if (MainWidget)
		{
			//MainWidget->SetEnabled(true);
			MainWidget->SetVisibility(EVisibility::Visible);
			//ShowAllLocationObjectTextWidget();
		}
	}
}

void AMainHUD::HideAllUI()
{
	if (GEngine&&GEngine->GameViewport)
	{
		if (MainWidget)
		{
			//MainWidget->SetEnabled(true);
			MainWidget->SetVisibility(EVisibility::Hidden);
			//HideAllLocationObjectTextWidget();
		}
	}
}

/*void AMainHUD::RemoveAllUI()
{
	if (GEngine&&GEngine->GameViewport)
	{
		if (MainTopWidget)
		{
			GEngine->GameViewport->RemoveViewportWidgetContent(MainTopWidget.ToSharedRef());
		}
		if (MainWidget)
		{
			GEngine->GameViewport->RemoveViewportWidgetContent(MainWidget.ToSharedRef());
		}
		if (TodaoMainWidget)
		{
			GEngine->GameViewport->RemoveViewportWidgetContent(TodaoMainWidget.ToSharedRef());
		}
		if (TDGZWidget)
		{
			GEngine->GameViewport->RemoveViewportWidgetContent(TDGZWidget.ToSharedRef());
		}
		if (InRoomMainWidget)
		{
			GEngine->GameViewport->RemoveViewportWidgetContent(InRoomMainWidget.ToSharedRef());
		}
	}
}*/
