// Fill out your copyright notice in the Description page of Project Settings.

#include "CourtyardCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

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



void ACourtyardCharacter::HookToLedge(FVector position, FVector scale) {
	hookedToLedge = true;
	//Each scale when set to default size is 50 units, don't change trigger size in blueprint
	float scaleRatio = 50;

	float xEdge = position.X - scaleRatio * scale.X;

	mLedgeLowerY = position.Y - scaleRatio * scale.Y;
	mLedgeHigherY = position.Y + scaleRatio * scale.Y;


	UCharacterMovementComponent* mov = GetCharacterMovement();
	mov->StopActiveMovement();
	mov->DisableMovement();

	/*
	FVector hookPosition = FVector(xEdge, GetActorLocation().Y, position.Z);

	FHitResult f;
	K2_SetActorLocation(hookPosition, false,f,true);
	*/
}

void ACourtyardCharacter::ReleaseFromLedge() {
	hookedToLedge = false;
	
}

bool ACourtyardCharacter::IsHookedToLedge() {
	return hookedToLedge;
}

bool ACourtyardCharacter::WithinConstriant() {
	if (!hookedToLedge) {
		return true;
	}
	else {
		if (GetActorLocation().Y > mLedgeLowerY && GetActorLocation().Y < mLedgeHigherY) {
			return true;
		}
		else {
			return false;
		}
	}
}
