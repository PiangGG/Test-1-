// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "ActorObject.generated.h"

UCLASS()
class LFS_API AActorObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;

	void BlockClicked(UPrimitiveComponent* ClickedComp);
	//Component
	class UStaticMeshComponent* StaticMeshComponent;

	//Component
	class UBoxComponent* BoxComponent;
};
