// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ItemObject/RobotActorObject.h"

#include "Components/WidgetComponent.h"
#include "UI/Widget/ActorObjectInfo/SRobotWidget.h"

ARobotActorObject::ARobotActorObject()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/ThirdPersonBP/JQR_1__jqrd-01.JQR_1__jqrd-01'"));
	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);

	WidgetComponent=CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(StaticMeshComponent);
	WidgetComponent->SetRelativeLocation(FVector(-200,0,400.0));

	StartLoation=GetActorLocation();
	CurrentLoation=StartLoation;
}

void ARobotActorObject::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (bIsShow)
	{
		UpdateForwardController();
	}
	
	UpdateLocation(DeltaSeconds);
}

EActorObjectEnum ARobotActorObject::GetObjectEnum()
{
	return  EActorObjectEnum::Robot;
}

void ARobotActorObject::OnMouseButton_Left_OnClick()
{
	Super::OnMouseButton_Left_OnClick();
	if (bIsShow)
	{
		Hide();
	}else
	{
		Show();
	}
	bIsShow=!bIsShow;
}

void ARobotActorObject::UpdateForwardController()
{
	FVector Location;
	Location=GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();

	//旋转
	FVector StartPos(GetActorLocation().X, GetActorLocation().Y, 0);
	FVector TargetPos(Location.X, Location.Y, 0);
	WidgetComponent->SetWorldRotation(FRotationMatrix::MakeFromX(TargetPos - StartPos).Rotator());
}

void ARobotActorObject::Show()
{
	if (WidgetComponent)
	{
		SAssignNew(RobotWidget, SRobotWidget);
		WidgetComponent->SetSlateWidget(RobotWidget);
		WidgetComponent->SetVisibility(true);
	}
}

void ARobotActorObject::Hide()
{
	if (WidgetComponent)
	{
		WidgetComponent->SetSlateWidget(nullptr);
		WidgetComponent->SetVisibility(false);
	}
}

void ARobotActorObject::UpdateLocation(float DeltaSeconds)
{
	if ((CurrentLoation-EndLoation).Size()>1.0f)
	{
		CurrentLoation=FMath::VInterpTo(CurrentLoation,EndLoation,DeltaSeconds,1.0f);
		SetActorRelativeLocation(CurrentLoation);
	}else
	{
		FVector TempLocation=EndLoation;
		EndLoation=StartLoation;
		StartLoation=TempLocation;
	}
}
