// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ActorObject.h"
#include "BatteryModuleActorObject.generated.h"

/**
 * 
 */
UCLASS()
class LFS_API ABatteryModuleActorObject : public AActorObject
{
	GENERATED_BODY()
	public:
	ABatteryModuleActorObject();
	public:
	virtual EActorObjectEnum GetObjectEnum() override;
};
