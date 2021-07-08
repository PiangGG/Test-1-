// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuController.generated.h"

/**
 * 
 */
UENUM()
enum ControllerLocation
{
	Main,
	Todao
};
UCLASS()
class LFS_API AMainMenuController : public APlayerController
{
	GENERATED_BODY()
public:
	AMainMenuController();

	void ChangeControllerLocation(ControllerLocation NewLocation);
	
private:
	
	ControllerLocation controllerLocation=ControllerLocation::Main;
};
