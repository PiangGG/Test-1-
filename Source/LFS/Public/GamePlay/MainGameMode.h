// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "Location/LocationTargetPoint.h"

#include "MainGameMode.generated.h"

/**
 * 
 */
USTRUCT()
struct FActorMatStruct
{
	GENERATED_USTRUCT_BODY()
	UStaticMesh *Mesh;
	TArray<UMaterialInterface*> MatArray;
};
UENUM()
enum class EWorldMode
{
	Mode1,//现实
	Mode2,//水晶
};
UCLASS()
class LFS_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

	public:
	AMainGameMode();

	void ChangePawn(AActor*actor);
	protected:
	virtual void BeginPlay() override;
	public:
	void ChangeCharacter(APawn *Pawn);
	//virtual  void SetPlayerDefaults(APawn* PlayerPawn) override;

	void ChangeAllStaticMeshMaterial();
	void ResetAllStatticMeshMaterial();
	void RecordAllStatticMeshMaterial();
	TArray<AActor*> AllActor;
	TArray<FActorMatStruct*> AllMaterials;
	//将要更换的材质
	UMaterialInterface* Materials;

	TArray<AActor*> HideActor;
	
	FTimerHandle TimerHandle;
	float JumpTime=1.0f;
	UFUNCTION()
	virtual void JumpActorLocation(AActor* LocationActor);
	
	UFUNCTION()
	void DelayCtrl();

	class AActor* JumpActor;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Target")
	FString StartTargetName;

	TArray<AActor*> LocationTargetPoints;

	void ChangeActorLocation(FString LocationName);

	UClass *SpawnCharatorClass;

	UPROPERTY()
	EWorldMode WorldMode;
	
	void ChangeWorldMode(EWorldMode newMode);

	//生成智能车
	class ARobotActorObject *RobotActorObject;
	void CreateCat();
	void ShowAllWorkObject();

	TArray<class AActor*>WorkObjectActors;
};
