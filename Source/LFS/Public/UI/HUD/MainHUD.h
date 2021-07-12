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
	NullState,MainState,TongDaoState,TDGZState,InRoomState
};
UCLASS()
class LFS_API AMainHUD : public AHUD
{
	GENERATED_BODY()
public:
	AMainHUD();
	
	TSharedPtr<class SMainWidget> MainWidget;
	
	TSharedPtr<class STodaoMainWidget> TodaoMainWidget;

	TSharedPtr<class STDGZWidget> TDGZWidget;
	
	TSharedPtr<class SInRoomMainWidget> InRoomMainWidget;
	HUDStateEnum CurrentState=HUDStateEnum::NullState;
	void ChangeHUDState(HUDStateEnum newState);

	protected:
	virtual void BeginPlay() override;

	TSharedPtr<class SCompoundWidget>InfoWidget;

	public:
	
	void ShowInfoWidget();
	void HideInfoWidget();

	void ShowCableInfoWidget();
	
	void ShowBatteryModuleInfoWidget();
};
