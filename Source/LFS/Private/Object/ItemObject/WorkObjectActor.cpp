// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ItemObject/WorkObjectActor.h"

#include "Components/TextRenderComponent.h"

AWorkObjectActor::AWorkObjectActor()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/ThirdPersonBP/Kaibishuo/Geometries/Box151.Box151'"));
	StaticMeshComponent->SetStaticMesh(StaticMesh.Object);

	TextRenderComponent=CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRenderComponent"));
	TextRenderComponent->SetupAttachment(RootComponent);
	TextRenderComponent->SetRelativeRotation(FRotator(0.0,90.0,0.0));
	TextRenderComponent->SetRelativeLocation(FVector(0.0f,100.0f,0.0f));
	TextRenderComponent->SetHorizontalAlignment(EHTA_Center);
	TextRenderComponent->SetVerticalAlignment(EVRTA_TextCenter);
	//Font=LoadObject<UFont>(NULL,TEXT("Font'/Engine/EngineFonts/Roboto.Roboto'"));
	//TextRenderComponent->SetFont(Font);
	//TextRenderComponent->
	MaterialInterface_R=LoadObject<UMaterialInstance>(NULL,TEXT("MaterialInstanceConstant'/Game/Material/StaticMesh/MI_WorkBoxActor_R.MI_WorkBoxActor_R'"));
	MaterialInterface_G=LoadObject<UMaterialInstance>(NULL,TEXT("MaterialInstanceConstant'/Game/Material/StaticMesh/MI_WorkBoxActor_G.MI_WorkBoxActor_G'"));
	TextRenderComponent->SetText(FText::FromString(""));
}

EActorObjectEnum AWorkObjectActor::GetObjectEnum()
{
	return EActorObjectEnum::WorkBox;
}

void AWorkObjectActor::OnMouseButton_Left_OnClick()
{
	Super::OnMouseButton_Left_OnClick();
	if (bShowState)
	{
		ChangeActorState(EWorkObjectActorState::Null);
	}else
	{
		ChangeActorState(WorkObjectActorState);
	}
	bShowState=!bShowState;
}

void AWorkObjectActor::ChangeActorState(EWorkObjectActorState newActorState)
{
	switch (newActorState)
	{
		case EWorkObjectActorState::Null:State_Null();break;
		case EWorkObjectActorState::DaiDian:State_DaiDian(); break;
		case EWorkObjectActorState::Workong:State_Working(); break;
		default:break;
	}
	//WorkObjectActorState=newActorState;
}

void AWorkObjectActor::State_Null()
{
	TextRenderComponent->SetVisibility(false);
	TextRenderComponent->SetText(FText::FromString(TEXT("")));
	for (int i=0;i<StaticMeshComponent->GetMaterials().Num();i++)
	{
		//StaticMeshComponent->SetMaterial(i,MaterialInterface_Base[i]);
	}
}

void AWorkObjectActor::State_DaiDian()
{
	TextRenderComponent->SetVisibility(true);
	TextRenderComponent->SetText(FText::FromString(FString(TEXT("带W"))+FString(TEXT("<br>")+FString(TEXT("电A"))+FString(TEXT("<br>"))+FString(TEXT("状I"))+FString(TEXT("<br>"))+FString(TEXT("态T")))));
	for (int i=0;i<StaticMeshComponent->GetMaterials().Num();i++)
	{
		StaticMeshComponent->SetMaterial(i,MaterialInterface_R);
	}
}

void AWorkObjectActor::State_Working()
{
	TextRenderComponent->SetVisibility(true);
	TextRenderComponent->SetText(FText::FromString(FString(TEXT("在W"))+FString(TEXT("<br>")+FString(TEXT("此O"))+FString(TEXT("<br>"))+FString(TEXT("作R"))+FString(TEXT("<br>"))+FString(TEXT("业K")))));
	for (int i=0;i<StaticMeshComponent->GetMaterials().Num();i++)
	{
		StaticMeshComponent->SetMaterial(i,MaterialInterface_G);
	}
}
