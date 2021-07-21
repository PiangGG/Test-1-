// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/TextObject/TextObjectActor.h"

#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
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
	WidgetComponent->SetVisibility(false);
	
}

// Called when the game starts or when spawned
void ATextObjectActor::BeginPlay()
{
	Super::BeginPlay();
	
	SAssignNew(TextInfoWidgetBase, STextInfoWidgetBase)
	.TextImage(TextImage);
	WidgetComponent->SetSlateWidget(TextInfoWidgetBase);
	
	//WidgetComponent->SetInitialLayerZOrder(1);
	TextInfoWidgetBase->SetLocationActor(this);
	
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
		TextInfoWidgetBase->SetVisibility(EVisibility::Visible);
		WidgetComponent->SetVisibility(true);
	}
}

void ATextObjectActor::HideWidget()
{
	if (TextInfoWidgetBase)
	{
		TextInfoWidgetBase->SetVisibility(EVisibility::Hidden);
		WidgetComponent->SetVisibility(false);	
	}
}

/*void ATextObjectActor::OnMouseButton_Left_OnClick()
{
	GetWorld()->GetFirstPlayerController()->SetViewTargetWithBlend(this,1);
}*/

