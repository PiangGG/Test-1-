// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "LocationTargetPoint.generated.h"

/**
 * 
 */
UCLASS()
class LFS_API ALocationTargetPoint : public ATargetPoint
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Target")
	FString TargetName;
};
