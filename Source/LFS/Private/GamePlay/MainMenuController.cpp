// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/MainMenuController.h"

#include "Object/ActorObject.h"
#include "UI/HUD/MainHUD.h"

AMainMenuController::AMainMenuController()
{
	
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
	}
}

void AMainMenuController::ShowMouse()
{
	bShowMouseCursor=!bShowMouseCursor;
}

void AMainMenuController::MouseOnclick_Left()
{
	if (bShowMouseCursor)
	{
		UE_LOG(LogTemp,Warning,TEXT("Onclick"));
		MouseOnClicActor=GetMouseOnClicActor();
		if (MouseOnClicActor)
		{
			switch (MouseOnClicActor->GetObjectEnum())
			{
				case Cable:
					Cast<AMainHUD>(GetHUD())->ShowCableInfoWidget();
					break;
				
				case BatteryModule:
					Cast<AMainHUD>(GetHUD())->ShowBatteryModuleInfoWidget();
					break;
					
				default:
					Cast<AMainHUD>(GetHUD())->ShowInfoWidget();
				 break;
			}
			
		}else
		{
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

AActorObject* AMainMenuController::GetMouseOnClicActor()
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
				FVector TranceEnd = TraceStar + (Dir * 10000);//射线的终点
 
				FCollisionQueryParams  TraceParams(FName(TEXT("Actor")), true, this);//给射线定义碰撞，并取一个名字
 
				//TraceParams.bTraceAsyncScene = true;//场景中所有碰撞
				TraceParams.bReturnPhysicalMaterial = false;//物理材质碰撞
				TraceParams.bTraceComplex = true;
 
				FHitResult hit(ForceInit);//初始化射线类并且发射一个射线
				GetWorld()->LineTraceSingleByChannel(hit, TraceStar, TranceEnd, ECC_Visibility, TraceParams);
				if (Cast<AActor>(hit.GetActor()))//打印被射线碰撞的物体
					{
						GEngine->AddOnScreenDebugMessage(-1, 0.8f, FColor::Blue, hit.GetActor()->GetName());
					}
				return Cast<AActorObject>(hit.GetActor());
			}
		}
	}
	return nullptr;
}
