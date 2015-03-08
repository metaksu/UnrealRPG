// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "Pickup_Rune.generated.h"

/**
*
*/

namespace Rune
{
	UENUM()
	enum Runes
	{
		Fire, Chaos, Air, Mind
	};
}

UCLASS()
class UNREALRPG_API APickup_Rune : public APickup
{
	GENERATED_BODY()

public:
	APickup_Rune(const FObjectInitializer& ObjectInitializer);

	float randomNum;
	float lowerRand, upperRand;

	Rune::Runes runeType;

	void setRuneType(float);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


};
