// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemObjectActor.h"

#include "CableActorObject.generated.h"

/**
 * 
 */
UCLASS()
class LFS_API ACableActorObject : public AItemObjectActor
{
	GENERATED_BODY()
	public:
	ACableActorObject();
	
	public:
	virtual EActorObjectEnum GetObjectEnum()override;

	virtual void OnMouseButton_Left_OnClick() override;
};
