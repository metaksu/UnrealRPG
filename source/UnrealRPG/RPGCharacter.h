// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Spell.h"
#include "GameFramework/Character.h"
#include "Pickup_Rune.h"
#include "RPGCharacter.generated.h"


UCLASS()
class UNREALRPG_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacter(const FObjectInitializer& ObjectInitializer);

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Projectile)
		TSubclassOf<ASpell> SpellToSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		UCameraComponent* RPGCharacterCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
		float Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
		float Gold;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats)
		float Experience;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = RuneStats)
		float airNum;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = RuneStats)
		float fireNum;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = RuneStats)
		float mindNum;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = RuneStats)
		float chaosNum;

	//FVector Location;

	void addGold(float);
	void removeGold(float);
	void addHealth(float);
	void removeHealth(float);
	void addExperience(float);
	void removeExperience(float);

	virtual void OnLanded(const FHitResult&);
	virtual void Falling();

	float startTime, totalTime;
	bool bIsFalling;
	bool bIsEPressed;
	void addRune(Runes, float);
private:
	



protected:
	void MoveRight(float Value);
	void MoveForward(float Value);
	void OnStartJump(float Value);
	void OnStopJump(float Value);

	/* Get the aim of the camera */
	FVector GetCameraAim() const;

	/* Frame rate independent turn */
	void TurnAtRate(float Val);

	/* Frame rate independent lookup */
	void LookUpAtRate(float Val);

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	float BaseTurnRate;

	void KeyEPressed();
	void KeyEReleased();

	void KeyFPressed();
	void KeyFReleased();


	/** Base lookup rate, in deg/sec. Other scaling may affect final lookup rate. */
	float BaseLookUpRate;
};
