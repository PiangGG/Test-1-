// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ActorObject.h"
#include "CableActorObject.generated.h"

/**
 * 
 */
UCLASS()
class LFS_API ACableActorObject : public AActorObject
{
	GENERATED_BODY()
	public:
	ACableActorObject();
	
	public:
	virtual EActorObjectEnum GetObjectEnum()override;
};
