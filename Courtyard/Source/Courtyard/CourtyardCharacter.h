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

	float mLedgeLowerY;
	float mLedgeHigherY;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Character")
	FVector GetAxisDirection(FVector dir);

	/*Setters and Getters*/
	
	UFUNCTION(BlueprintCallable, Category = "Character")
	void HookToLedge(FVector position, FVector scale);
	UFUNCTION(BlueprintCallable, Category = "Character")
	void ReleaseFromLedge();
	UFUNCTION(BlueprintCallable, Category = "Character")
	bool IsHookedToLedge();
	UFUNCTION(BlueprintCallable, Category = "Character")
	bool WithinConstriant();

private:
	bool movementEnabled;
	bool hookedToLedge;

	
	
	
};
