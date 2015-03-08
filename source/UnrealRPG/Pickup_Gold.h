// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "RPGCharacter.h"
#include "Pickup_Gold.generated.h"

/**
*
*/
UCLASS()
class UNREALRPG_API APickup_Gold : public APickup
{
	GENERATED_BODY()

public:

	APickup_Gold(const FObjectInitializer& ObjectInitializer);

	float lowerRange, upperRange;
	float randomNum;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;



};
