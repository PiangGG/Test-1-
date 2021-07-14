// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MainGameMode.h"

#include "GameFramework/DefaultPawn.h"
#include "GamePlay/MainCharacter.h"
#include "GamePlay/MainMenuController.h"
#include "UI/HUD/MainHUD.h"

AMainGameMode::AMainGameMode()
{
	PlayerControllerClass=AMainMenuController::StaticClass();
	HUDClass=AMainHUD::StaticClass();
	//DefaultPawnClass=AMainCharacter::StaticClass();
}

void AMainGameMode::ChangeCharacter(APawn *Pawn)
{
	if (Cast<AMainCharacter>(Pawn))
	{
		DefaultPawnClass=AMainCharacter::StaticClass();
	}else
	{
		DefaultPawnClass=ADefaultPawn::StaticClass();;
	}
	
}
