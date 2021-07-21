// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainLevelPawn.generated.h"

UCLASS()
class LFS_API AMainLevelPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainLevelPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleDefaultsOnly,Category="LFS")
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleDefaultsOnly,Category="LFS")
	class UCameraComponent* ThirdCamera;

	//玩家控制器指针
	class AMainMenuController *MainController;

	float BaseZomm=50000.0f;
	float CurrentZoom;
	float ChangeSpeed=10.0f;
	void IncreaseZoom(float var);
};
