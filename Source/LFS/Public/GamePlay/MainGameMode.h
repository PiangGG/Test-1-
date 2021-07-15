// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LFS_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

	public:
	AMainGameMode();

	protected:
	virtual void BeginPlay() override;
	public:
	void ChangeCharacter(APawn *Pawn);
	//virtual  void SetPlayerDefaults(APawn* PlayerPawn) override;

	void ChangeAllStaticMeshMaterial();
	void ResetAllStatticMeshMaterial();
	void RecordAllStatticMeshMaterial();

	//将要更换的材质
	UMaterialInterface* Materials;
		
	TArray<class AStaticMeshActor*> WorldAllActors;
	TArray<UMaterialInterface*> UMaterials;
};
