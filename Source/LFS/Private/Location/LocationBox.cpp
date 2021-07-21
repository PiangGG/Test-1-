// Fill out your copyright notice in the Description page of Project Settings.


#include "Location/LocationBox.h"

#include "Components/BoxComponent.h"
#include "GamePlay/MainCharacter.h"
#include "GamePlay/MainGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/MainHUD.h"

// Sets default values
ALocationBox::ALocationBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxComponent->SetupAttachment(RootComponent);
	
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this,&ALocationBox::OverlapCompBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this,&ALocationBox::OverlapCompEnd);
}

// Called when the game starts or when spawned
void ALocationBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALocationBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALocationBox::OverlapCompBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning,TEXT("OverlapCompBegin"));
	APawn*Character=Cast<APawn>(OtherActor);
	if (Character)
	{
		ChangeNewLocationState(BoxState);
	}
}
void ALocationBox::OverlapCompEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp,Warning,TEXT("OverlapCompEnd"));
	AMainHUD* HUD=Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD());
	if (!HUD)return;
	switch (HUD->CurrentState)
	{
	case NullState:
		ChangeNewLocationState(LocationBoxState::LocationNullState);
		break;
	case MainState:
		ChangeNewLocationState(LocationBoxState::LocationNullState);
		break;
	case TongDaoState:
		ChangeNewLocationState(LocationBoxState::LocationNullState);
		break;
	case InRoomState:
		ChangeNewLocationState(LocationBoxState::LocationNullState);
		break;
	case TDGZState:
		ChangeNewLocationState(LocationBoxState::LocationTongDaoState);
		break;
	default:
		ChangeNewLocationState(LocationBoxState::LocationNullState);
		break;
	}
}

void ALocationBox::ChangeNewLocationState(LocationBoxState newState)
{
	//AMainGameMode *GM=Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GWorld));
	AMainHUD* HUD=Cast<AMainHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD());
	if (!HUD)return;
	switch (newState)
	{
	case LocationBoxState::LocationNullState:
		HUD->ChangeHUDState(HUDStateEnum::NullState);
		break;
	case LocationBoxState::LocationMainStat:
		HUD->ChangeHUDState(HUDStateEnum::MainState);
		break;
	case LocationBoxState::LocationTongDaoState:
		HUD->ChangeHUDState(HUDStateEnum::TongDaoState);
		break;
	case LocationBoxState::LocationTDGZState:
		HUD->ChangeHUDState(HUDStateEnum::TDGZState);
		break;
	case LocationBoxState::LocationInRoomState:
		HUD->ChangeHUDState(HUDStateEnum::InRoomState);
		break;
	default:break ;
	}
}
