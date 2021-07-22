// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ItemObject/ItemObjectActor.h"
#include "MonitorObjectActor2.generated.h"

/**
 * 
 */
UCLASS()
class LFS_API AMonitorObjectActor2 : public AItemObjectActor
{
	GENERATED_BODY()
	public:
	AMonitorObjectActor2();
	virtual void Tick(float DeltaSeconds) override;
	public:
	virtual EActorObjectEnum GetObjectEnum()override;

	virtual void OnMouseButton_Left_OnClick() override;

	void UpdateForwardController();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Component)
	class UWidgetComponent* WidgetComponent;

	TSharedPtr<class SMoitorJKWidget> MoitorJKWidget;
	
	void Show();

	void Hide();

	bool bIsShow=false;
};
