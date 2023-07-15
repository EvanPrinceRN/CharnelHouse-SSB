// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Engine/DataAsset.h"
#include "InputDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class CHARNELHOUSE_API UInputDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)		//Input Action for Player Movement.
	TObjectPtr<UInputAction> Movement;
	
	UPROPERTY(EditAnywhere)		//Input Action for Camera Control.
	TObjectPtr<UInputAction> Camera;
	
	UPROPERTY(EditAnywhere)		//Input Action for Sprinting.
	TObjectPtr<UInputAction> Sprint;
	
	UPROPERTY(EditAnywhere)		//Input Action for Jumping.
	TObjectPtr<UInputAction> Jump;
	
	UPROPERTY(EditAnywhere)		//Input Action for Dodging.
	TObjectPtr<UInputAction> Dodge;
	
	UPROPERTY(EditAnywhere)		//Input Action for Pausing and Un-Pausing the Game.
	TObjectPtr<UInputAction> Pause;
};
