// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ItemObject/CableActorObject.h"

#include "UI/HUD/MainHUD.h"

ACableActorObject::ACableActorObject()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/guanlang/Geometries/Line001.Line001'"));
	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
}

EActorObjectEnum ACableActorObject::GetObjectEnum()
{
	return EActorObjectEnum::Cable;
}

void ACableActorObject::OnMouseButton_Left_OnClick()
{
	Super::OnMouseButton_Left_OnClick();
	Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ShowCableInfoWidget();
}
