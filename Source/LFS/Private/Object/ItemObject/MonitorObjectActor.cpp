// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ItemObject/MonitorObjectActor.h"

#include "UI/HUD/MainHUD.h"

AMonitorObjectActor::AMonitorObjectActor()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/fangwu/Geometries/SXJQJ-01_2.SXJQJ-01_2'"));
	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
}

EActorObjectEnum AMonitorObjectActor::GetObjectEnum()
{
	return EActorObjectEnum::Monitor;
}

void AMonitorObjectActor::OnMouseButton_Left_OnClick()
{
	Super::OnMouseButton_Left_OnClick();
	Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ShowBatteryModuleInfoWidget();
}
