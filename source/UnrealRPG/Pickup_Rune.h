// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "Pickup_Rune.generated.h"

/**
*
*/

enum class Runes : short
{
	Fire, Chaos, Air, Mind
};

UCLASS()
class UNREALRPG_API APickup_Rune : public APickup
{
	GENERATED_BODY()

public:
	APickup_Rune(const FObjectInitializer& ObjectInitializer);

	UMaterial* AirRunes;
	UMaterial* MindRunes;
	UMaterial* ChaosRunes;
	UMaterial* FireRunes;

	float randomNum, randomNum1;
	float lowerRand, upperRand, lowerRand2, upperRand2;

	Runes runeType;

	void setRuneType(float);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


};
