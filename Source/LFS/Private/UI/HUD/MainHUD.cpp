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
			SAssignNew(MainTopWidget, SMainTopWidget);
			GEngine->GameViewport->AddViewportWidgetContent(MainTopWidget.ToSharedRef(),-50);
		}
		break;
	case MainState:
		if (GEngine&&GEngine->GameViewport)
		{
			GEngine->GameViewport->RemoveAllViewportWidgets();
			SAssignNew(MainWidget, SMainWidget);
			GetWorld()->GetGameViewport()->AddViewportWidgetContent(MainWidget.ToSharedRef(),-50);
		}
		break;
	case TongDaoState:
		if (GEngine&&GEngine->GameViewport)
		{
			GEngine->GameViewport->RemoveAllViewportWidgets();
			SAssignNew(TodaoMainWidget, STodaoMainWidget);
			GEngine->GameViewport->AddViewportWidgetContent(TodaoMainWidget.ToSharedRef(),-50);
		}
		break;
	case TDGZState:
			SAssignNew(TDGZWidget, STDGZWidget);
			GEngine->GameViewport->AddViewportWidgetContent(TDGZWidget.ToSharedRef(),-50);
			break;
	case InRoomState:
		if (GEngine&&GEngine->GameViewport)
		{
			GEngine->GameViewport->RemoveAllViewportWidgets();
			SAssignNew(InRoomMainWidget, SInRoomMainWidget);
			GEngine->GameViewport->AddViewportWidgetContent(InRoomMainWidget.ToSharedRef(),-50);
		}
		break;
	default:
		break;
	}
	CurrentState=newState;
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
