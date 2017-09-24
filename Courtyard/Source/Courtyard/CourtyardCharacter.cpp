// Fill out your copyright notice in the Description page of Project Settings.

#include "CourtyardCharacter.h"


// Sets default values
ACourtyardCharacter::ACourtyardCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACourtyardCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	movementEnabled = true;
	hookedToLedge = false;
}

// Called every frame
void ACourtyardCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACourtyardCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACourtyardCharacter::EnableMovement() {
	movementEnabled = true;

}

void ACourtyardCharacter::DisableMovement() {
	movementEnabled = false;
}

bool ACourtyardCharacter::IsMovementEnabled() {
	return movementEnabled;
}


void ACourtyardCharacter::HookToLedge() {
	isHookedToEdge = true;
}

void ACourtyardCharacter::ReleaseFromLedge() {
	IsHookedToLedge = false;
}

bool ACourtyardCharacter::IsHookedToLedge() {
	return hookedToLedge;
}
