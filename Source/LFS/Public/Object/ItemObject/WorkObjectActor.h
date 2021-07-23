// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ItemObject/ItemObjectActor.h"
#include "WorkObjectActor.generated.h"

/**
 * 
 */
UENUM()
enum class EWorkObjectActorState:uint8
{
	Null,DaiDian,Workong
};
UCLASS()
class LFS_API AWorkObjectActor : public AItemObjectActor
{
	GENERATED_BODY()
	public:
	AWorkObjectActor();
	public:
	virtual EActorObjectEnum GetObjectEnum() override;
	virtual void OnMouseButton_Left_OnClick() override;

	/*
	 * Component
	 */
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UTextRenderComponent* TextRenderComponent;
	class UFont *Font;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	EWorkObjectActorState WorkObjectActorState=EWorkObjectActorState::Null;

	UMaterialInterface* MaterialInterface_R;
	UMaterialInterface* MaterialInterface_G;

	bool bShowState = false;
	void ChangeActorState(EWorkObjectActorState newActorState);

	void State_Null();
	void State_DaiDian();
	void State_Working();
};
