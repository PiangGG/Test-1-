// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ItemObject/ItemObjectActor.h"
#include "MonitorObjectActor.generated.h"

/**
 * 
 */
UCLASS()
class LFS_API AMonitorObjectActor : public AItemObjectActor
{
	GENERATED_BODY()
	public:
	AMonitorObjectActor();
	public:
	virtual EActorObjectEnum GetObjectEnum() override;
	virtual void OnMouseButton_Left_OnClick() override;
};
