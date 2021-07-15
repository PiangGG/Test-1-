// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ItemObject/BatteryModuleActorObject.h"

#include "UI/HUD/MainHUD.h"

ABatteryModuleActorObject::ABatteryModuleActorObject()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/ThirdPersonBP/Peidianshuo/Geometries/BXGJXG-01.BXGJXG-01'"));
	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
}

EActorObjectEnum ABatteryModuleActorObject::GetObjectEnum()
{
	return EActorObjectEnum::BatteryModule;
}

void ABatteryModuleActorObject::OnMouseButton_Left_OnClick()
{
	Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ShowBatteryModuleInfoWidget();
}
