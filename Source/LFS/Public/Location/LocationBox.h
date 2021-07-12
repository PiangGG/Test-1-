// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocationBox.generated.h"

UENUM(BlueprintType)
enum class LocationBoxState: uint8
{
	LocationNullState,LocationMainStat,LocationTongDaoState,LocationTDGZState,LocationInRoomState
};

UCLASS()
class LFS_API ALocationBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALocationBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Component")
	class UBoxComponent *BoxComponent;

	UFUNCTION()
	virtual void OverlapCompBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep ,const FHitResult & SweepResult);
	UFUNCTION()
	virtual void OverlapCompEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void ChangeNewLocationState(LocationBoxState newState);

	public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	LocationBoxState BoxState=LocationBoxState::LocationMainStat;;

};
