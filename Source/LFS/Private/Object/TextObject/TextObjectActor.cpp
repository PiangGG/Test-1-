// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/TextObject/TextObjectActor.h"

#include "Components/WidgetComponent.h"
#include "GamePlay/MainCharacter.h"
#include "GamePlay/MainGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/MainHUD.h"
#include "UI/Widget/TextInfoWidget/STextInfoWidgetBase.h"

// Sets default values
ATextObjectActor::ATextObjectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp=CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	RootComponent=RootComp;
	
	WidgetComponent=CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(RootComp);
	//WidgetComponent->is
	
}

// Called when the game starts or when spawned
void ATextObjectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Show();
	WidgetComponent->SetVisibility(false);
	TextInfoWidgetBase->SetLocationActor(this);
}

void ATextObjectActor::Show()
{
	if (WidgetComponent)
	{
		SAssignNew(TextInfoWidgetBase, STextInfoWidgetBase)
		.TextImage(TextImage)
		.OnClickedImage_UObject(this,&ATextObjectActor::OnImageOnclick);
		WidgetComponent->SetSlateWidget(TextInfoWidgetBase);
		WidgetComponent->SetVisibility(true);
	}
}

void ATextObjectActor::Hide()
{
	if (WidgetComponent)
	{
		WidgetComponent->SetSlateWidget(nullptr);
		WidgetComponent->SetVisibility(false);
	}
}

void ATextObjectActor::OnImageOnclick()
{
	if (this&&UGameplayStatics::GetPlayerController(GWorld,0))
	{
		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->SpawnCharatorClass=AMainCharacter::StaticClass();
		Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld))->JumpActorLocation(this);
	}
}

// Called every frame
void ATextObjectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateForwardController();
}

void ATextObjectActor::UpdateForwardController()
{
	FVector Location;
	Location=GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();

	//旋转
	FVector StartPos(GetActorLocation().X, GetActorLocation().Y,  GetActorLocation().Z);
	FVector TargetPos(Location.X, Location.Y, Location.Z);
	WidgetComponent->SetWorldRotation(FRotationMatrix::MakeFromX(TargetPos - StartPos).Rotator());
}

void ATextObjectActor::ShowWidget()
{
	if (TextInfoWidgetBase)
	{
		Show();
	}
}

void ATextObjectActor::HideWidget()
{
	if (TextInfoWidgetBase)
	{
		Hide();
	}
}

void ATextObjectActor::ChangeUIState()
{
	
}
