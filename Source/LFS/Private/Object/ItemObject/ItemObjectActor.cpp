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
	MaterialInterface_Hide=LoadObject<UMaterial>(NULL,TEXT("Material'/Game/Material/StaticMesh/Hightline.Hightline'"));
}

// Called when the game starts or when spawned
void AItemObjectActor::BeginPlay()
{
	Super::BeginPlay();
	MaterialInterface_Base=StaticMeshComponent->GetMaterials();
}

// Called every frame
void AItemObjectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemObjectActor::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
}

void AItemObjectActor::BlockClicked(UPrimitiveComponent* ClickedComp)
{
	UE_LOG(LogTemp,Warning,TEXT("BlockClicked"));
}

void AItemObjectActor::OnMouseButton_Left_OnClick()
{
	Super::OnMouseButton_Left_OnClick();
	//bSelected=true;
	for (int i=0;i<StaticMeshComponent->GetMaterials().Num();i++)
	{
		StaticMeshComponent->SetMaterial(i,MaterialInterface_Hide);
	}
}

void AItemObjectActor::ReSetMaterial()
{
	for (int i=0;i<MaterialInterface_Base.Num();i++)
	{
		StaticMeshComponent->SetMaterial(i,MaterialInterface_Base[i]);
	}
}
