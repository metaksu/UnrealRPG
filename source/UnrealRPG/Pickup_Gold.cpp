// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealRPG.h"
#include "Pickup_Gold.h"
#include "RPGCharacter.h"


APickup_Gold::APickup_Gold(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void APickup_Gold::BeginPlay() {
	lowerRange = 5;
	upperRange = 200;
}

// Called every frame
void APickup_Gold::Tick(float DeltaTime)
{
	if (bHasCollided)
	{
		ARPGCharacter* MyCharacter = Cast<ARPGCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
		randomNum = FMath::FRandRange(lowerRange, upperRange);
		MyCharacter->addGold(randomNum);
		this->Destroy();
	}
}
