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
	WidgetComponent->SetVisibility(true);
}

// Called when the game starts or when spawned
void ATextObjectActor::BeginPlay()
{
	Super::BeginPlay();
	SAssignNew(TextInfoWidgetBase, STextInfoWidgetBase)
	.TextImage(TextImage);
	WidgetComponent->SetSlateWidget(TextInfoWidgetBase);
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

	/*FVector len=WidgetComponent->GetComponentLocation()-Location;
	WidgetComponent->SetRelativeScale3D(len*0.001);*/
}

void ATextObjectActor::OnMouseButton_Left_OnClick()
{
	GetWorld()->GetFirstPlayerController()->SetViewTargetWithBlend(this,1);
}

