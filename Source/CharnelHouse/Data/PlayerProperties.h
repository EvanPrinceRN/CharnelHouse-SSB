// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerProperties.generated.h"

/**
 * 
 */
UCLASS()
class CHARNELHOUSE_API UPlayerProperties : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float MaxHealth;
	UPROPERTY(EditAnywhere)
	float WalksSpeed = 150;
	UPROPERTY(EditAnywhere)
	float SprintSpeed = 400;
	UPROPERTY(EditAnywhere)
	float JumpHeight = 400;

	UPROPERTY(EditAnywhere, Category=Camera)
	float MouseXSensitivity = 20;
	UPROPERTY(EditAnywhere, Category=Camera)
	float MouseYSensitivity = 20;

};
