// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CourtyardCharacter.generated.h"

UCLASS(Blueprintable)
class COURTYARD_API ACourtyardCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACourtyardCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	/*Setters and Getters*/
	UFUNCTION(BlueprintCallable, Category="Character")
	void EnableMovement();
	UFUNCTION(BlueprintCallable, Category = "Character")
	void DisableMovement();
	UFUNCTION(BlueprintCallable, Category = "Character")
	bool IsMovementEnabled();
	
	UFUNCTION(BlueprintCallable, Category = "Character")
	void HookToLedge();
	UFUNCTION(BlueprintCallable, Category = "Character")
	void ReleaseFromLedge();
	UFUNCTION(BlueprintCallable, Category = "Character")
	bool IsHookedToLedge();

private:
	bool movementEnabled;
	bool hookedToLedge;

	
	
	
};
