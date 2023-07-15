// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DissidentController.generated.h"

/**
 * 
 */
UCLASS()
class CHARNELHOUSE_API ADissidentController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category=EnhancedInput)
	TObjectPtr<class UInputMappingContext> CharacterMappingContext;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category=EnhancedInput)
	TObjectPtr<class UInputDataAsset> InputActions;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	TObjectPtr<class ADissident> Dissident;

private:
	virtual void OnPossess(APawn* InPawn) override;
};
