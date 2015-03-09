// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealRPG.h"
#include "Pickup.h"
#include "RPGCharacter.h"


// Sets default values
APickup::APickup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupCollision = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("PickupCollision"));

	RootComponent = PickupCollision;

	PickupMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));

	PickupMesh->SetSimulatePhysics(false);



}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	bIsActive = true;
	bHasCollided = false;

}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	PickupCollision->GetOverlappingActors(MainPlayer, ARPGCharacter::StaticClass());

	if (MainPlayer.Num() == 1)
	{
		bHasCollided = true;
	}
	else
	{
		bHasCollided = false;
	}


}

void APickup::OnPickedUp()
{

}

void APickup::PhysicsOn()
{
	PickupMesh->SetSimulatePhysics(true);
}

void APickup::PhysicsOff()
{
	PickupMesh->SetSimulatePhysics(false);
}
