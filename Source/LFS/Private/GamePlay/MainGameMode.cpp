// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MainGameMode.h"

#include "GamePlay/MainCharacter.h"
#include "GamePlay/MainMenuController.h"
#include "UI/HUD/MainHUD.h"

AMainGameMode::AMainGameMode()
{
	PlayerControllerClass=AMainMenuController::StaticClass();
	HUDClass=AMainHUD::StaticClass();
	DefaultPawnClass=AMainCharacter::StaticClass();
}