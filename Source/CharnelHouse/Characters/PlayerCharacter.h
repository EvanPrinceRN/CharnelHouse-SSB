// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharnelCharacter.h"
#include "PlayerCharacter.generated.h"

class UPlayerDataAsset;
struct FInputActionValue;

UCLASS()
class CHARNELHOUSE_API APlayerCharacter : public ACharnelCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)	// Spring Component.					
	TObjectPtr< class USpringArmComponent > SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)	// Camera Component.
	TObjectPtr< class UCameraComponent > CameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)	// Stores all modifiable Player Properties.				
	TObjectPtr< UPlayerDataAsset > PlayerProperties;

	UPROPERTY(EditDefaultsOnly)						// Dodging Montage.
	TObjectPtr< UAnimMontage > DodgeMontage;

private:
	FVector DodgeDirection;
	
public:
	virtual void BeginPlay() override;						// Called when the game starts or when spawned.
	virtual void Tick( float DeltaTime ) override;			// Called every frame.
	void Move( const FInputActionValue& Axis );				// Handles Player Movement Code.
	void CameraControl( const FInputActionValue& Axis );	// Handles Camera Control Code.
	void BeginSprint( const FInputActionValue& BoolValue );	// Handles Sprinting Code.
	void Dodge( const FInputActionValue& BoolValue );		// Handles Dodging Code.

private:
	virtual void InitializeHealth() override;		// Sets the Health Values of the Player.
};
