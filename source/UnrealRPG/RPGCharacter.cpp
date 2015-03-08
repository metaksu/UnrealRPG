// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealRPG.h"
#include "RPGCharacter.h"


// Sets default values
ARPGCharacter::ARPGCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RPGCharacterCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("RPGCharacterCameraComponent"));

	GetMesh()->AttachParent = GetCapsuleComponent();
	GetMesh()->AttachParent = RPGCharacterCameraComponent;
	Health = 100;
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

}

// Called when the game starts or when spawned
void ARPGCharacter::BeginPlay()
{

}

// Called every frame
void ARPGCharacter::Tick(float DeltaTime)
{

}

// Called to bind functionality to input
void ARPGCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &ARPGCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARPGCharacter::MoveRight);
	InputComponent->BindAxis("TurnAtRate", this, &ARPGCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUpAtRate", this, &ARPGCharacter::LookUpAtRate);

	//InputComponent->BindAction("Jump", IE_Pressed, this, &ARPGCharacter::OnStartJump);
	//InputComponent->BindAction("Jump", IE_Released, this, &ARPGCharacter::OnStopJump);
}

//Movement right - left
void ARPGCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void ARPGCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ARPGCharacter::TurnAtRate(float Val)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Val * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ARPGCharacter::LookUpAtRate(float Val)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Val * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ARPGCharacter::addGold(float Val)
{
	Gold += Val;
}

void ARPGCharacter::removeGold(float Val)
{
	Gold -= Val;
}

void ARPGCharacter::addRune(Rune::Runes takeInRune, float numRunes)
{
	switch (takeInRune)
	{
	case Rune::Fire:
		fireNum += numRunes;
		break;
	case Rune::Chaos:
		chaosNum += numRunes;
		break;
	case Rune::Air:
		airNum += numRunes;
		break;
	case Rune::Mind:
		mindNum += numRunes;
		break;
	default:
		break;
	}
}

