// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/BaseActorObject.h"

// Sets default values
ABaseActorObject::ABaseActorObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseActorObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseActorObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

EActorObjectEnum ABaseActorObject::GetObjectEnum()
{
	return EActorObjectEnum::Cable;
}

void ABaseActorObject::OnMouseButton_Left_OnClick()
{
	
}
