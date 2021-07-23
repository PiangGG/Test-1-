// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UENUM()
enum class HUDStateEnum : uint8 
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
	//TSubclassOf<class UUserWidget> UserMainWidget;
	
	TSharedPtr<class SMainTopWidget> MainTopWidget;
	//TSubclassOf<class UUserWidget> UserMainTopWidget;
	
	TSharedPtr<class STodaoMainWidget> TodaoMainWidget;

	TSharedPtr<class STDGZWidget> TDGZWidget;
	
	TSharedPtr<class SInRoomMainWidget> InRoomMainWidget;

	UUserWidget *CurrentWidget;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	HUDStateEnum CurrentState=HUDStateEnum::NullState;

	UFUNCTION(BlueprintCallable)
	void ChangeHUDState(HUDStateEnum newState);

	protected:
	virtual void BeginPlay() override;

	TSharedPtr<class SCompoundWidget>InfoWidget;

	public:
	void ShowInfoWidget();
	void HideInfoWidget();

	void ShowCableInfoWidget();
	void ShowBatteryModuleInfoWidget();
	void ShowMonitorInfoWidget();
	void ShowMonitor2InfoWidget();
	
	UFUNCTION(BlueprintCallable)
	void ShowAllLocationObjectTextWidget();
	UFUNCTION(BlueprintCallable)
	void HideAllLocationObjectTextWidget();
	UFUNCTION(BlueprintCallable)
	void RemoveAllUI();
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TArray<class AActor*>TextObjectActor;
};
