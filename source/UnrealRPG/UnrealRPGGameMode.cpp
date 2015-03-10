// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealRPG.h"
#include "UnrealRPGGameMode.h"

AUnrealRPGGameMode::AUnrealRPGGameMode(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnOb(TEXT("/Game/Character/BP_Character"));
	DefaultPawnClass = PlayerPawnOb.Class;
}

