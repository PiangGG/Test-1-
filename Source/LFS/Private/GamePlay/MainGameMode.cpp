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
#include "Object/ItemObject/RobotActorObject.h"
#include "Object/ItemObject/WorkObjectActor.h"
#include "Object/TextObject/TextObjectActor.h"
#include "UI/HUD/MainHUD.h"

AMainGameMode::AMainGameMode()
{
	PlayerControllerClass=AMainMenuController::StaticClass();
	HUDClass=AMainHUD::StaticClass();
	DefaultPawnClass=ADefaultPawn::StaticClass();

	//变换后的材质
	//ConstructorHelpers::FObjectFinder<UMaterialInterface>Material(TEXT("MaterialInstanceConstant'/Game/Material/StaticMesh/MI_WorkBoxActor_G.MI_WorkBoxActor_G'"));
	MaterialInterface=LoadObject<UMaterialInstance>(NULL,TEXT("MaterialInstanceConstant'/Game/Material/StaticMesh/MI_WorkBoxActor_R.MI_WorkBoxActor_R'"));
	//MaterialInterface=Material.Object;
	
	WorldMode=EWorldMode::Mode1;
}

void AMainGameMode::ChangePawn(AActor* actor)
{
	APawn *player2=GWorld->SpawnActor<APawn>(ADefaultPawn::StaticClass(),actor->GetActorLocation(),actor->GetActorRotation());
	UGameplayStatics::GetPlayerController(GWorld,0)->Possess(player2);
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

	for (int i=0;i<AllActor.Num();i++)
	{
		for (int j=0;j<Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->GetMaterials().Num();j++)
		{
			if (AllActor[i])
			{
				Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->SetMaterial(j,MaterialInterface);
				//Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->SetMaterial(j,AllMaterials[i]->MatArray[0]);
			}
		}
	}
	for (int i =0;i<HideActor.Num();i++)
	{
		HideActor[i]->SetActorHiddenInGame(true);
	}
}

void AMainGameMode::ResetAllStatticMeshMaterial()
{
	UE_LOG(LogTemp,Warning,TEXT("AMainGameMode::ResetAllStatticMeshMaterial()"));
	for (int i=0;i<AllActor.Num();i++)
	{
		for (int j=0;j<Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->GetMaterials().Num();j++)
		{
			if (AllMaterials.IsValidIndex(i)&&AllMaterials[i]->MatArray.IsValidIndex(j))
			{
				Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->SetMaterial(j,AllMaterials[i]->MatArray[j]);
			}
		}
	}
	for (int i =0;i<HideActor.Num();i++)
	{
		HideActor[i]->SetActorHiddenInGame(false);
	}
}

void AMainGameMode::RecordAllStatticMeshMaterial()
{
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AStaticMeshActor::StaticClass(),AllActor);
	AllMaterials.Reset(AllActor.Num());
	for (int i=0;i<AllActor.Num();i++)
	{
		FActorMatStruct* ActorMatStruct = new FActorMatStruct();
		//if (ActorMatStruct)
		{
			ActorMatStruct->Mesh=Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->GetStaticMesh();
			ActorMatStruct->MatArray=(Cast<AStaticMeshActor>(AllActor[i])->GetStaticMeshComponent()->GetMaterials());
			AllMaterials.Add(ActorMatStruct);
		}
	}
	UGameplayStatics::GetAllActorsWithTag(GetWorld(),FName("Hide"),HideActor);
	
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
		if (Cast<ATextObjectActor>(JumpActor))
		{
			switch (Cast<ATextObjectActor>(JumpActor)->TextObjectActorState)
			{
			case ETextObjectActorState::DLTD:
				Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD())->ChangeHUDState(HUDStateEnum::TongDaoState);
				break;
			case ETextObjectActorState::KBS:
				Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD())->ChangeHUDState(HUDStateEnum::InRoomState);
				break;
			case ETextObjectActorState::PDF:
				Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD())->ChangeHUDState(HUDStateEnum::InRoomState);
				break;
			case ETextObjectActorState::DLSJ:
				Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD())->ChangeHUDState(HUDStateEnum::MainState);
				ChangePawn(JumpActor);
				break;
			default:
				Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD())->ChangeHUDState(HUDStateEnum::NullState);
				break;
			}
		}else
		{
			Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD())->ChangeHUDState(HUDStateEnum::NullState);	
		}
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

void AMainGameMode::ChangeWorldMode(EWorldMode newMode)
{
	WorldMode=newMode;
	switch (WorldMode)
	{
		case EWorldMode::Mode1:
			ResetAllStatticMeshMaterial();
			if (Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->CurrentState==HUDStateEnum::MainState)
			{
				Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ChangeHUDState(HUDStateEnum::NullState);
			}
			break;
		case EWorldMode::Mode2:
			ChangeAllStaticMeshMaterial();
			
			if (Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->CurrentState==HUDStateEnum::NullState)
			{
				Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ChangeHUDState(HUDStateEnum::MainState);
			}
			/*if (Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->CurrentState==HUDStateEnum::InRoomState)
			{
				
			}*/
			break;
		default: break;
	}
}

void AMainGameMode::CreateCat()
{
	UE_LOG(LogTemp,Warning,TEXT("CreateCat()"));
	FVector Vector1=FVector(88.9,-204.3,-328.4);
	FRotator Rotator1=FRotator((0.0,269.9,0.0));
	RobotActorObject=GetWorld()->SpawnActor<ARobotActorObject>(ARobotActorObject::StaticClass(),Vector1,Rotator1);
	RobotActorObject->Show();
	RobotActorObject->StartLoation=FVector((68.9,-204.3,-328.4));
	RobotActorObject->EndLoation=FVector((-1011.0,-204.3,-328.4));
}
void AMainGameMode::ShowAllWorkObject()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AWorkObjectActor::StaticClass(),WorkObjectActors);
	for (int i =0;i<WorkObjectActors.Num();i++)
	{
		Cast<AWorkObjectActor>(WorkObjectActors[i])->OnMouseButton_Left_OnClick();
	}
}