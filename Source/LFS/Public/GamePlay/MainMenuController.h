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

	
	void ChnageLocation1();
	
	void ChnageLocation2();
	
	void ChnageLocation3();
private:
	ControllerLocation controllerLocation=ControllerLocation::Main;
	
	AActor* StartActor;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void MoveForward(float var);
	void MoveRight(float var);
	void Turn(float var);
	void Lookup(float var);

	void ShowMouse();
	void MouseOnclick_Left();
	void FocusActor(AActor *actor);

	void ChangeAllStaticMeshMaterial();
	void ResetAllStatticMeshMaterial();
	
	//鼠标位置发射一个射线
	class ABaseActorObject* GetMouseOnClicActor();
	
	class ABaseActorObject* MouseOnClicActor = nullptr;


};

