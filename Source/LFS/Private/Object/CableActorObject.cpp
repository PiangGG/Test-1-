// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/CableActorObject.h"

ACableActorObject::ACableActorObject()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/guanlang/Geometries/Line001.Line001'"));
	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
}

EActorObjectEnum ACableActorObject::GetObjectEnum()
{
	return EActorObjectEnum::Cable;
}
