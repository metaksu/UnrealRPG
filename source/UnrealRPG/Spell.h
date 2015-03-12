
#pragma once

#include "GameFramework/Actor.h"
#include "Spell.generated.h"


UCLASS()
class UNREALRPG_API ASpell : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpell(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Cast)
		UParticleSystemComponent* CastedSpell;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Cast)
		UParticleSystemComponent* Explosion;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		USphereComponent* SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		UProjectileMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		float Speed;

	void Move(const APawn& Target);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;



};
