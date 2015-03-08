// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealRPG.h"
#include "Spell.h"


// Sets default values
ASpell::ASpell(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 100;

	CastedSpell = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("CastedSpell"));
	Explosion = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Explosion"));

	CastedSpell->ActivateSystem(true);
	Explosion->ActivateSystem(true);

	CastedSpell->bVisible = true;
	Explosion->bVisible = false;

	MovementComponent = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("MovementComponent"));
	MovementComponent->bIsHomingProjectile = true;

	CastedSpell->AttachParent = RootComponent;
	Explosion->AttachParent = RootComponent;
}

// Called when the game starts or when spawned
void ASpell::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

