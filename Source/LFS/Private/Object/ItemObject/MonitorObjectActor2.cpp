// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ItemObject/MonitorObjectActor2.h"
#include "Components/WidgetComponent.h"
#include "UI/HUD/MainHUD.h"
#include "UI/Widget/ActorObjectInfo/SMoitorJKWidget.h"

AMonitorObjectActor2::AMonitorObjectActor2()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/fangwu/Geometries/SXJQJ-01_2.SXJQJ-01_2'"));
	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);

	WidgetComponent=CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(StaticMeshComponent);
	WidgetComponent->SetRelativeLocation(FVector(0,0,200.0));
}

void AMonitorObjectActor2::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (bIsShow)
	{
		UpdateForwardController();
	}
}

void AMonitorObjectActor2::UpdateForwardController()
{
	FVector Location;
	Location=GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();

	//旋转
	FVector StartPos(GetActorLocation().X, GetActorLocation().Y, 0);
	FVector TargetPos(Location.X, Location.Y, 0);
	WidgetComponent->SetWorldRotation(FRotationMatrix::MakeFromX(TargetPos - StartPos).Rotator());
}

void AMonitorObjectActor2::Show()
{
	if (WidgetComponent)
	{
		SAssignNew(MoitorJKWidget, SMoitorJKWidget);
		WidgetComponent->SetSlateWidget(MoitorJKWidget);
		WidgetComponent->SetVisibility(true);
		UE_LOG(LogTemp,Warning,TEXT("SHOW"));
	}
}

void AMonitorObjectActor2::Hide()
{
	if (WidgetComponent)
	{
		WidgetComponent->SetSlateWidget(nullptr);
		WidgetComponent->SetVisibility(false);
		UE_LOG(LogTemp,Warning,TEXT("HIDE"));
		//WidgetComponent->ReceiveHardwareInput(true);
		//WidgetComponent->SetInitialLayerZOrder(1);
	}
}

EActorObjectEnum AMonitorObjectActor2::GetObjectEnum()
{
	return EActorObjectEnum::Monitor2;
}

void AMonitorObjectActor2::OnMouseButton_Left_OnClick()
{
	Super::OnMouseButton_Left_OnClick();
	if (bIsShow)
	{
		Hide();
	}else
	{
		Show();
	}
	bIsShow=!bIsShow;
}
