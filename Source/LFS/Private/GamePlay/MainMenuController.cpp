// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MainMenuController.h"

#include "Engine/StaticMeshActor.h"
#include "GameFramework/PlayerStart.h"
#include "GamePlay/MainGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Object/ItemObject/ItemObjectActor.h"
#include "UI/HUD/MainHUD.h"
#include "Widgets/SViewport.h"

AMainMenuController::AMainMenuController()
{
	//ConstructorHelpers::FObjectFinder<UMaterial>MaterialInstance(TEXT("MaterialInstanceConstant'/Game/Material/StaticMesh/Hightline_Inst.Hightline_Inst'"));
	//'LoadObject<U>()
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

void AMainMenuController::BeginPlay()
{
	Super::BeginPlay();
	ChangeControllerLocation(controllerLocation);
}

void AMainMenuController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction("ShowMouse",IE_Pressed,this,&AMainMenuController::ShowMouse);
		
		InputComponent->BindAction("MouseOnclick_Left",IE_Pressed,this,&AMainMenuController::MouseOnclick_Left);

		InputComponent->BindAction("ChangeMode",IE_Pressed,this,&AMainMenuController::ChangeMode);
		
		InputComponent->BindAction("ChnageLocation1",IE_Pressed,this,&AMainMenuController::ChnageLocation1);
		InputComponent->BindAction("ChnageLocation2",IE_Pressed,this,&AMainMenuController::ChnageLocation2);
		InputComponent->BindAction("ChnageLocation3",IE_Pressed,this,&AMainMenuController::ChnageLocation3);
		InputComponent->BindAction("ChnageLocation4",IE_Pressed,this,&AMainMenuController::ChnageLocation4);
	}
}

void AMainMenuController::ShowMouse()
{
	bShowMouseCursor=!bShowMouseCursor;
	if (bShowMouseCursor)
	{
		SetInputMode(FInputModeGameAndUI());
	}else
	{
		SetInputMode(FInputModeGameOnly());
	}
}

void AMainMenuController::MouseOnclick_Left()
{
	if (bShowMouseCursor)
	{
		if (MouseOnClicActor)
		{
			Cast<AItemObjectActor>(MouseOnClicActor)->ReSetMaterial();		
		}
		MouseOnClicActor=GetMouseOnClicActor();
		if (MouseOnClicActor)
		{
			MouseOnClicActor->OnMouseButton_Left_OnClick();
		
		}else
		{
			
			//UE_LOG(LogTemp,Warning,TEXT("Onclick"));
			Cast<AMainHUD>(GetHUD())->HideInfoWidget();
		}
	}
}

void AMainMenuController::MoveForward(float var)
{
	
}

void AMainMenuController::MoveRight(float var)
{
}

void AMainMenuController::Turn(float var)
{
}

void AMainMenuController::Lookup(float var)
{
}

void AMainMenuController::FocusActor(AActor* actor)
{
	
}

ABaseActorObject* AMainMenuController::GetMouseOnClicActor()
{
	FVector CamLoc;
	FRotator CamRot;

	this->GetPlayerViewPoint(CamLoc, CamRot);
	APlayerController* pc = GetWorld()->GetFirstPlayerController();
	if (pc)
	{
		ULocalPlayer* localplayer = pc->GetLocalPlayer();
		if (localplayer && localplayer->ViewportClient)
		{
			FVector Dir,pint;
			if (pc->DeprojectMousePositionToWorld(pint,Dir))//得到鼠标点击的位置和方向
				{
				FVector TraceStar = CamLoc;//摄像机所在位置
				FVector Direction = CamRot.Vector();//摄像机所看方向//实际上这个方向也可以发射一个射线出去，判断是否在前方
				//射线的终点
				FVector TranceEnd = TraceStar + (Dir * 1000000);//射线的终点
 
				FCollisionQueryParams  TraceParams(FName(TEXT("Actor")), true, this);//给射线定义碰撞，并取一个名字
 
				//TraceParams.bTraceAsyncScene = true;//场景中所有碰撞
				TraceParams.bReturnPhysicalMaterial = false;//物理材质碰撞
				TraceParams.bTraceComplex = true;
 
				FHitResult hit(ForceInit);//初始化射线类并且发射一个射线
				
				if (!bIstransparent)
				{
					GetWorld()->LineTraceSingleByChannel(hit, TraceStar, TranceEnd, ECC_Visibility, TraceParams);
					if (Cast<AActor>(hit.GetActor()))//打印被射线碰撞的物体
					{
						GEngine->AddOnScreenDebugMessage(-1, 0.8f, FColor::Blue, hit.GetActor()->GetName());
					}
				}else
				{
					GetWorld()->LineTraceSingleByChannel(hit, TraceStar, TranceEnd,ECC_GameTraceChannel1,TraceParams);
					if (Cast<AActor>(hit.GetActor()))
					{
						GEngine->AddOnScreenDebugMessage(-1, 0.8f, FColor::Blue, hit.GetActor()->GetName()+"666");
					}
				}
				return Cast<ABaseActorObject>(hit.GetActor());
			}
		}
	}
	return nullptr;
}

void AMainMenuController::ChnageLocation1()
{
	UGameplayStatics::OpenLevel(GetWorld(),FName("laifushi"));
	//GetWorld()->GetFirstPlayerController()->SetViewTargetWithBlend(StartActor,1);
}

void AMainMenuController::ChnageLocation2()
{
	UGameplayStatics::OpenLevel(GetWorld(),FName("Fangzhi"));
}

void AMainMenuController::ChnageLocation3()
{
	UGameplayStatics::OpenLevel(GetWorld(),FName("NewMap"));
}
void AMainMenuController::ChnageLocation4()
{
	UGameplayStatics::OpenLevel(GetWorld(),FName("TongDao"));
}

void AMainMenuController::ChangeMode()
{
	if (bIstransparent)
	{
		ResetAllStatticMeshMaterial();
	}else
	{
		ChangeAllStaticMeshMaterial();
	}
	bIstransparent=!bIstransparent;
}
