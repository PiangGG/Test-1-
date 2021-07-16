// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MainGameMode.h"

#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/DefaultPawn.h"
#include "GamePlay/MainCharacter.h"
#include "GamePlay/MainMenuController.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/MainHUD.h"

AMainGameMode::AMainGameMode()
{
	PlayerControllerClass=AMainMenuController::StaticClass();
	HUDClass=AMainHUD::StaticClass();
	//DefaultPawnClass=AMainCharacter::StaticClass();

	//变换后的材质
	ConstructorHelpers::FObjectFinder<UMaterialInterface>Material(TEXT("MaterialInstanceConstant'/Game/ThirdPersonBP/ThirdPersonBP/NewMaterial_2_Inst.NewMaterial_2_Inst'"));
	Materials=Material.Object;
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	//RecordAllStatticMeshMaterial();
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

void AMainGameMode::ChangeAllStaticMeshMaterial()
{
	UE_LOG(LogTemp,Warning,TEXT("AMainGameMode::ChangeAllStaticMeshMaterial()"));
	for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
	{
		AStaticMeshActor* Actor=*It;
		int mnumber=Actor->GetStaticMeshComponent()->GetNumMaterials();
		for (int i=0;i<mnumber;i++)
		{
			Actor->GetStaticMeshComponent()->SetMaterial(0,Materials);
		}
	}
}

void AMainGameMode::ResetAllStatticMeshMaterial()
{
	for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
	{
		AStaticMeshActor* Actor=*It;
		Actor->Reset();
	}
}

void AMainGameMode::RecordAllStatticMeshMaterial()
{
	for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
	{
		AStaticMeshActor* Actor=*It;
		UMaterials.Add(Actor->GetStaticMeshComponent()->GetMaterial(0));
	}
}
