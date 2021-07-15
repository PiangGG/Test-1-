// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ItemObject/ItemObjectActor.h"
// Sets default values
AItemObjectActor::AItemObjectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent=StaticMeshComponent;
	//StaticMeshComponent->OnClicked.AddDynamic(this,&AActorObject::BlockClicked);

	
	BoxComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComponent->SetupAttachment(RootComponent);

	/*BoxComponent->OnClicked.AddDynamic(this,&AActorObject::NotifyActorOnClicked);
	OnClicked.AddUniqueDynamic(this, &AActorObject::NotifyActorOnClicked);*/
}

// Called when the game starts or when spawned
void AItemObjectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemObjectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemObjectActor::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("NotifyActorOnClicked"), false);
	UE_LOG(LogTemp,Warning,TEXT("NotifyActorOnClicked"));
}

void AItemObjectActor::BlockClicked(UPrimitiveComponent* ClickedComp)
{
	UE_LOG(LogTemp,Warning,TEXT("BlockClicked"));
}


