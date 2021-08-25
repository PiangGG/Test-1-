// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemObjectActor.h"
#include "Engine/TargetPoint.h"
#include "Object/BaseActorObject.h"
#include "RobotActorObject.generated.h"

/**
 * 
 */
UCLASS()
class LFS_API ARobotActorObject : public AItemObjectActor
{
	GENERATED_BODY()
	public:
	ARobotActorObject();
	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;
	public:
	virtual EActorObjectEnum GetObjectEnum()override;

	virtual void OnMouseButton_Left_OnClick() override;

	void UpdateForwardController();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Component)
	class UWidgetComponent* WidgetComponent;

	TSharedPtr<class SRobotWidget> RobotWidget;
	
	void Show();

	void Hide();

	bool bIsShow=false;

	public:
	TArray<AActor*> MoveTargetPoints;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class ATargetPoint *StartLoation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class ATargetPoint* EndLoation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector CurrentLoation;

	void UpdateLocation(float DeltaSeconds);
};

