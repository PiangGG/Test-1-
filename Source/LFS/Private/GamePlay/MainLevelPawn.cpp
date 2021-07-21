// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MainLevelPawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMainLevelPawn::AMainLevelPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//摄像机手臂
	CameraBoom=CreateDefaultSubobject<USpringArmComponent>(TEXT("CamerBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = BaseZomm;
	CameraBoom->TargetOffset = FVector(0.0f,0.0f,60.0f);
	CameraBoom->bUsePawnControlRotation = true;//绑定Controller旋转

	//初始化相机
	ThirdCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdCamera"));
	ThirdCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	ThirdCamera->bUsePawnControlRotation= false;

	CurrentZoom=BaseZomm;
	ChangeSpeed= 1000;
}

// Called when the game starts or when spawned
void AMainLevelPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainLevelPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMainLevelPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn",this,&AMainLevelPawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp",this,&AMainLevelPawn::AddControllerPitchInput);
	
	PlayerInputComponent->BindAxis("IncreaseZoom",this,&AMainLevelPawn::IncreaseZoom);
}

void AMainLevelPawn::IncreaseZoom(float var)
{
	BaseZomm+=(ChangeSpeed*var);
	CameraBoom->TargetArmLength = BaseZomm;
}