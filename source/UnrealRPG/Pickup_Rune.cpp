// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealRPG.h"
#include "Pickup_Rune.h"
#include "RPGCharacter.h"


APickup_Rune::APickup_Rune(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

	
	
	static ConstructorHelpers::FObjectFinder<UMaterial> AirRune(TEXT("/Game/Runes/AirRune_Mat"));
	static ConstructorHelpers::FObjectFinder<UMaterial> ChaosRune(TEXT("/Game/Runes/ChaosRune_Mat"));
	static ConstructorHelpers::FObjectFinder<UMaterial> FireRune(TEXT("/Game/Runes/FireRune_Mat"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MindRune(TEXT("/Game/Runes/MindRune_Mat"));

	AirRunes = AirRune.Object;
	ChaosRunes = ChaosRune.Object;
	FireRunes = FireRune.Object;
	MindRunes = MindRune.Object;
	

	
	//static ConstructorHelpers::FObjectFinder<UMaterialInterface> MindRune(TEXT("/Game/Runes/MindRune_Mat"));
	//runeType = Runes::Mind;
	//PickupMesh->SetMaterial(0, MindRune.Object);
}

void APickup_Rune::BeginPlay() {
	lowerRand = 1;
	upperRand = 6;
	lowerRand2 = 2;
	upperRand2 = 5;

	randomNum1 = FMath::FRandRange(lowerRand2, upperRand2);

	switch ((int)randomNum1)
	{

	case 1:
		PickupMesh->SetMaterial(0, AirRunes);
		runeType = Runes::Air;

		break;
	case 2:
		PickupMesh->SetMaterial(0, ChaosRunes);
		runeType = Runes::Chaos;
		break;
	case 3:
		PickupMesh->SetMaterial(0, FireRunes);
		runeType = Runes::Fire;
		break;
	case 4:
		PickupMesh->SetMaterial(0, MindRunes);
		runeType = Runes::Mind;
		break;
	default:
		runeType = Runes::Air;
		PickupMesh->SetMaterial(0, AirRunes);
		break;
	}

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

