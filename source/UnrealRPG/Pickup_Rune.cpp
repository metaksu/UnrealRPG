// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealRPG.h"
#include "Pickup_Rune.h"
#include "RPGCharacter.h"


APickup_Rune::APickup_Rune(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	randomNum = FMath::FRandRange(1, 5);
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> AirRune(TEXT("/Game/Runes/AirRune_Mat"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ChaosRune(TEXT("/Game/Runes/ChaosRune_Mat"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> FireRune(TEXT("/Game/Runes/FireRune_Mat"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MindRune(TEXT("/Game/Runes/MindRune_Mat"));
	switch ((int)randomNum)
	{

	case 1:
		PickupMesh->SetMaterial(0, AirRune.Object);
		runeType = Runes::Air;
		
		break;
	case 2:
		PickupMesh->SetMaterial(0, ChaosRune.Object);
		runeType = Runes::Chaos;
		break;
	case 3:
		PickupMesh->SetMaterial(0, FireRune.Object);
		runeType = Runes::Fire;
		break;
	case 4:
		PickupMesh->SetMaterial(0, MindRune.Object);
		runeType = Runes::Mind;	
		break;
	default:
		runeType = Runes::Air;
		PickupMesh->SetMaterial(0, AirRune.Object);
		break;
	}
	/*
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MindRune(TEXT("/Game/Runes/MindRune_Mat"));
	runeType = Rune::Mind;
	PickupMesh->SetMaterial(0, MindRune.Object);*/
}

void APickup_Rune::BeginPlay() {
	lowerRand = 1;
	upperRand = 6;
}

// Called every frame
void APickup_Rune::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ARPGCharacter* MyCharacter = Cast<ARPGCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (bHasCollided && MyCharacter->bIsEPressed)
	{
		
		randomNum = FMath::FRandRange(lowerRand, upperRand);
		
		MyCharacter->addRune(runeType, (int)randomNum);
		this->Destroy();
	}
}

void APickup_Rune::setRuneType(float takeIn)
{
	/*
	* 1 = air
	* 2 = chaos
	* 3 = fire
	* 4 = mind
	*/

	switch ((int)takeIn)
	{
	case 1:
		runeType = Runes::Air;
		break;
	case 2:
		runeType = Runes::Chaos;
		break;
	case 3:
		runeType = Runes::Fire;
		break;
	case 4:
		runeType = Runes::Mind;
		break;
	default:
		runeType = Runes::Air;
		break;

	}
}

