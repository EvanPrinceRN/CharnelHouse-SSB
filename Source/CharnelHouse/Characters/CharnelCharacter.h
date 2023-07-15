// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MotionWarpingComponent.h"
#include "CharnelCharacter.generated.h"

class UMotionWarpingComponent;
class UHealthMeter;

UCLASS(HideCategories=(Character))
class CHARNELHOUSE_API ACharnelCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharnelCharacter();

	UPROPERTY(BlueprintReadWrite)					// Contains All Character Health Functionality
	TObjectPtr<UHealthMeter> Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		// Motion Warping Component.				
	TObjectPtr<UMotionWarpingComponent> MotionWarpingComponent;

private:
	bool bSprinting = false;
	bool bDodging   = false;
	bool bJumping   = false;

public:
	UFUNCTION(BlueprintPure) 				// Getter for Sprinting
	bool GetSprinting() { return bSprinting; }

	UFUNCTION(BlueprintCallable)			// Setter for Sprinting
	void SetSprinting( bool sprinting ) { bSprinting = sprinting; }

	UFUNCTION(BlueprintPure)				// Getter for Dodging 
	bool GetDodging() { return bDodging; }

	UFUNCTION(BlueprintCallable)			// Setter for Dodging 
	void SetDodging( bool dodging ) { bDodging = dodging; }

private:
	virtual void InitializeHealth(){};		// Sets Default Values for the Character's Health
};
