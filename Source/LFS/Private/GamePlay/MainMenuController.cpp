// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MainMenuController.h"

AMainMenuController::AMainMenuController()
{
	ChangeControllerLocation(controllerLocation);
}

void AMainMenuController::ChangeControllerLocation(ControllerLocation NewLocation)
{
	controllerLocation=NewLocation;
	switch (NewLocation)
	{
		case Main:break;
		case Todao: break;
		
		default: break;
	}
}
