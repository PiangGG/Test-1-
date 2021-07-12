// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/BatteryModuleActorObject.h"

ABatteryModuleActorObject::ABatteryModuleActorObject()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/ThirdPersonBP/Peidianshuo/Geometries/BXGJXG-01.BXGJXG-01'"));
	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
}

EActorObjectEnum ABatteryModuleActorObject::GetObjectEnum()
{
	return EActorObjectEnum::BatteryModule;
}
