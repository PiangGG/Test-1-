// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MainCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetEnableGravity(false);
	
	//摄像机手臂
	CameraBoom=CreateDefaultSubobject<USpringArmComponent>(TEXT("CamerBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 0.0f;
	CameraBoom->TargetOffset = FVector(0.0f,0.0f,60.0f);
	CameraBoom->bUsePawnControlRotation = true;//绑定Controller旋转

	//初始化相机
	ThirdCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdCamera"));
	ThirdCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	ThirdCamera->bUsePawnControlRotation= false;//设置第三人称相机不跟随控制器旋转
	//GetCharacterMovement()->GravityScale=0.0f;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this,&AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn",this,&AMainCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp",this,&AMainCharacter::AddControllerPitchInput);
}

void AMainCharacter::MoveForward(float Value)
{
	if (Value!=0&&Controller)
	{
		//const FRotator Rotation = Controller->GetDesiredRotation();
		//FVector Dirction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(GetActorForwardVector(),Value);
	}
}

void AMainCharacter::MoveRight(float Value)
{
	if (Value!=0)
	{
		//const FQuat Rotation = GetActorQuat();
		//FVector Dirction = FQuatRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(GetActorRightVector(),Value);
	}
}

void AMainCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}


void AMainCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

