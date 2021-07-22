// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/BaseActorObject.h"

#include "TextObjectActor.generated.h"

UCLASS()
class LFS_API ATextObjectActor : public ABaseActorObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATextObjectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Show();
	void Hide();

	UFUNCTION()
	void OnImageOnclick();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//更新图形始终朝向控制器
	void UpdateForwardController();
	//跟组件
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Component)
	class USceneComponent* RootComp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Component)
	class USceneComponent* TargetComp;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Component)
	class UWidgetComponent* WidgetComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Component)
	FSlateBrush TextImage;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Component)
	TSharedPtr<class STextInfoWidgetBase>TextInfoWidgetBase;

	/*UFUNCTION()
	virtual void OnMouseButton_Left_OnClick() override;*/

	AActor * TargetActor;

	FVector TargetActorLocation;
	FRotator TargetActorRotator;

	void ShowWidget();
	void HideWidget();
};
