// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealRPG.h"
#include "Pickup_Rune.h"
#include "RPGCharacter.h"

using namespace Rune;

APickup_Rune::APickup_Rune(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MindRune(TEXT("/Game/Runes/MindRune_Mat"));
	runeType = Rune::Mind;
	PickupMesh->SetMaterial(0, MindRune.Object);
}

void APickup_Rune::BeginPlay() {
	lowerRand = 1;
	upperRand = 5;
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
		runeType = Rune::Air;
		break;
	case 2:
		runeType = Rune::Chaos;
		break;
	case 3:
		runeType = Rune::Fire;
		break;
	case 4:
		runeType = Rune::Mind;
		break;
	default:
		runeType = Rune::Air;
		break;

	}
}

