// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MainGameMode.h"

#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/DefaultPawn.h"
#include "GamePlay/MainCharacter.h"
#include "GamePlay/MainLevelPawn.h"
#include "GamePlay/MainMenuController.h"
#include "Kismet/GameplayStatics.h"
#include "Location/LocationTargetPoint.h"
#include "UI/HUD/MainHUD.h"

AMainGameMode::AMainGameMode()
{
	PlayerControllerClass=AMainMenuController::StaticClass();
	HUDClass=AMainHUD::StaticClass();
	DefaultPawnClass=ADefaultPawn::StaticClass();

	//变换后的材质
	ConstructorHelpers::FObjectFinder<UMaterialInterface>Material(TEXT("MaterialInstanceConstant'/Game/ThirdPersonBP/ThirdPersonBP/NewMaterial_2_Inst.NewMaterial_2_Inst'"));
	Materials=Material.Object;
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	RecordAllStatticMeshMaterial();
	ChangeActorLocation(FString("Start"));
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

	/*for (int i=0;i<AllActor.Num();i++)
	{
		for (int j=0;j<Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->GetMaterials().Num();j++)
		{
			Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->SetMaterial(j,Materials);
		}
		
	}*/
	
}

void AMainGameMode::ResetAllStatticMeshMaterial()
{
	/*for (int i=0;i<AllActor.Num();i++)
	{
		for (int j=0;j<Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->GetMaterials().Num();j++)
		{
			Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->SetMaterial(j,AllMaterials[j]);
		}
	}*/
}

void AMainGameMode::RecordAllStatticMeshMaterial()
{
	/*UGameplayStatics::GetAllActorsOfClass(GetWorld(),AStaticMeshActor::StaticClass(),AllActor);

	for (int i=0;i<AllActor.Num();i++)
	{
		AllMaterials.Append(Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->GetMaterials());
	}
	*/
}

void AMainGameMode::JumpActorLocation(AActor* LocationActor)
{
	JumpActor=LocationActor;
	if (JumpActor&&UGameplayStatics::GetPlayerController(GWorld,0))
	{
		UGameplayStatics::GetPlayerController(GWorld,0)->SetViewTargetWithBlend(JumpActor,2);
		FTimerDelegate UpdateTimerDelegate=FTimerDelegate::CreateUObject(this,&AMainGameMode::DelayCtrl);
		GetWorld()->GetTimerManager().SetTimer(TimerHandle,UpdateTimerDelegate,2.0f,false);
	}
}

void AMainGameMode::DelayCtrl()
{
	if (JumpActor&&SpawnCharatorClass)
	{
		APawn *player=GWorld->SpawnActor<APawn>(SpawnCharatorClass,JumpActor->GetActorLocation(),JumpActor->GetActorRotation());
		UGameplayStatics::GetPlayerController(GWorld,0)->Possess(player);
		GWorld->GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD())->ChangeHUDState(HUDStateEnum::NullState);
	}
}

void AMainGameMode::ChangeActorLocation(FString LocationName)
{
	SpawnCharatorClass=AMainLevelPawn::StaticClass();
	for (TActorIterator<ALocationTargetPoint> It(GetWorld()); It; ++It)
	{
		ALocationTargetPoint* LocationTargetPoint=*It;
		if (LocationTargetPoint->TargetName == LocationName)
		{
			JumpActorLocation(LocationTargetPoint);
		}
	}
}
