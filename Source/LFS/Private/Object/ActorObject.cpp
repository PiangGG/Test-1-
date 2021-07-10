// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ActorObject.h"

// Sets default values
AActorObject::AActorObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/guanlang/Geometries/Line001.Line001'"));
	StaticMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
	
	RootComponent=StaticMeshComponent;
	//StaticMeshComponent->OnClicked.AddDynamic(this,&AActorObject::BlockClicked);

	
	BoxComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComponent->SetupAttachment(RootComponent);

	/*BoxComponent->OnClicked.AddDynamic(this,&AActorObject::NotifyActorOnClicked);
	OnClicked.AddUniqueDynamic(this, &AActorObject::NotifyActorOnClicked);*/
}

// Called when the game starts or when spawned
void AActorObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorObject::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("NotifyActorOnClicked"), false);
	UE_LOG(LogTemp,Warning,TEXT("Onclick"));
}

void AActorObject::BlockClicked(UPrimitiveComponent* ClickedComp)
{
	UE_LOG(LogTemp,Warning,TEXT("Onclick"));
}

