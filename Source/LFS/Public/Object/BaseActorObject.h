// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActorObject.generated.h"

//点击设备的枚举，根据不同设备显示UI
UENUM()
enum EActorObjectEnum
{
	Cable,BatteryModule,TextImage,Monitor,Monitor2,Robot
};

UCLASS()
class LFS_API ABaseActorObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseActorObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	public:
	virtual EActorObjectEnum GetObjectEnum();

	virtual void OnMouseButton_Left_OnClick();
};
