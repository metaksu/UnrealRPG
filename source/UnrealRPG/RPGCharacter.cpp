// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealRPG.h"
#include "RPGCharacter.h"


// Sets default values
ARPGCharacter::ARPGCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	RPGCharacterCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("RPGCharacterCameraComponent"));
	RPGCharacterCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	RPGCharacterCameraComponent->bUsePawnControlRotation = false;

	

	Health = 100;
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	Gold = 0;
	fireNum = 0;
	airNum = 0;
	mindNum = 0;
	chaosNum = 0;

	bIsEPressed = false;	
	
}

// Called every frame
void ARPGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARPGCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	InputComponent->BindAxis("MoveForward", this, &ARPGCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARPGCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ARPGCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ARPGCharacter::LookUpAtRate);
	InputComponent->BindAction("TakeItem", IE_Pressed,this, &ARPGCharacter::KeyEPressed);
	InputComponent->BindAction("TakeItem", IE_Released, this, &ARPGCharacter::KeyEReleased);

}


void ARPGCharacter::MoveRight(float Value)
{

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ARPGCharacter::MoveForward(float Value)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

//Movement right - left
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

FVector ARPGCharacter::GetCameraAim() const
{

	FVector FinalAim = FVector::ZeroVector;


	if (Controller)
	{
		FVector	CamLoc;
		FRotator CamRot;
		Controller->GetPlayerViewPoint(CamLoc, CamRot);
		FinalAim = CamRot.Vector();
	}

	return FinalAim;

}

void ARPGCharacter::KeyEPressed()
{
	bIsEPressed = true;
}

void ARPGCharacter::KeyEReleased()
{
	bIsEPressed = false;
}

void ARPGCharacter::addGold(float Val)
{
	if (bIsEPressed)
		Gold += Val;
}

void ARPGCharacter::removeGold(float Val)
{
	Gold -= Val;
}

void ARPGCharacter::addHealth(float Val)
{
	Health += Val;
}

void ARPGCharacter::removeHealth(float Val)
{
	Health -= Val;
}

void ARPGCharacter::addExperience(float Val)
{
	Experience += Val;
}

void ARPGCharacter::removeExperience(float Val)
{
	Experience -= Val;
}

void ARPGCharacter::addRune(Rune::Runes takeInRune, float numRunes)
{ 
	//If this doesn't work test without if statement
	if (bIsEPressed)
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
	
}

