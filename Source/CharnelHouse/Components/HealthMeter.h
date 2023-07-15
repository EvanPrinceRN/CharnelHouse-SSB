// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HealthMeter.generated.h"

/**
 * 
 */
UCLASS()
class CHARNELHOUSE_API UHealthMeter : public UObject
{
	GENERATED_BODY()

	float MaxHealth;
	float CurrentHealth;

public:
	UFUNCTION(BlueprintPure)		// Returns the character's MAX HEALTH.
	float GetMaxHealth() { return MaxHealth; }

	UFUNCTION(BlueprintCallable)	// Sets the Character's MAX HEALTH.
	void SetMaxHealth(float NewMaxHealth) { MaxHealth = NewMaxHealth; }
	
	UFUNCTION(BlueprintPure)		// Returns the character's CURRENT HEALTH.
	float GetCurrentHealth() { return CurrentHealth; }

	UFUNCTION(BlueprintCallable)	// Sets the character's CURRENT HEALTH.
	void SetCurrentHealth( float amount ) { MaxHealth = amount; }
};
