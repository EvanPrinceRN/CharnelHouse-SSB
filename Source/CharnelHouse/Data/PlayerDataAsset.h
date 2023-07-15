// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class CHARNELHOUSE_API UPlayerDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HEALTH")	// Character's Max Health Value.
	float MaxHealth = 100.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOVEMENT")	// Character's Walking Speed.
	float WalkSpeed = 200.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOVEMENT")	// Character's Jogging Speed.
	float JogSpeed = 500.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOVEMENT")	// Character's Sprinting Speed.
	float SprintSpeed = 1000.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="MOVEMENT")// Character's Jump Height.
	float JumpHeight = 1000.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="DODGE")	// Character's Dodge Distance.
	float DodgeDistance = 1500.f;	
	
};
