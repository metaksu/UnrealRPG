// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class UNREALRPG_API APickup : public AActor
{
	GENERATED_BODY()

public:
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
		bool bIsActive;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
		USphereComponent* PickupCollision;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
		UStaticMeshComponent* PickupMesh;

	TArray<AActor*> MainPlayer;


	bool bHasCollided;
	void OnPickedUp();
	void PhysicsOn();
	void PhysicsOff();

	// Sets default values for this actor's properties
	APickup(const FObjectInitializer&);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;



};
