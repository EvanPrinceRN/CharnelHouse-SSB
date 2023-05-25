// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "InputActions.generated.h"

/**
 * 
 */
UCLASS()
class CHARNELHOUSE_API UInputActions : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,Category=Player)
	UInputAction* IA_Move;
	UPROPERTY(EditAnywhere,Category=Player)
	UInputAction* IA_Camera;
	UPROPERTY(EditAnywhere,Category=Player)
	UInputAction* IA_Jump;
	UPROPERTY(EditAnywhere,Category=Player)
	UInputAction* IA_Sprint;
	UPROPERTY(EditAnywhere,Category=Player)
	UInputAction* IA_Dodge;
	UPROPERTY(EditAnywhere,Category=Player)
	UInputAction* IA_Block;
	UPROPERTY(EditAnywhere,Category=Player)
	UInputAction* IA_LightAttack;
	UPROPERTY(EditAnywhere,Category=Player)
	UInputAction* IA_HeavyAttack;

	UPROPERTY(EditAnywhere,Category=MappingContexts)
	UInputMappingContext* BaseMappingContext;
};
