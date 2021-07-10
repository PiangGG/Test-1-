// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UENUM()
enum HUDStateEnum
{
	NullState,MainState,TongDaoState
};
UCLASS()
class LFS_API AMainHUD : public AHUD
{
	GENERATED_BODY()
public:
	AMainHUD();
	
	TSharedPtr<class SMainWidget> MainWidget;
	
	TSharedPtr<class STodaoMainWidget> TodaoMainWidget;
	HUDStateEnum CurrentState=HUDStateEnum::NullState;
	void ChangeHUDState(HUDStateEnum newState);

	protected:
	virtual void BeginPlay() override;

	TSharedPtr<class SActorObjectInfoMainWidget>InfoWidget;

	public:
	
	void ShowInfoWidget();
	void HideInfoWidget();
};
