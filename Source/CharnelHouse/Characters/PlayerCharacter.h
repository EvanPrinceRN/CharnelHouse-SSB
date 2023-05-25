// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystemInterface.h"
#include "CharnelHouse/Data/PlayerProperties.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCharacter.generated.h"

class UInputMappingContext;

UCLASS(HideCategories=("Character","Camera","Actor Tick","Replication","Rendering","Collision","Actor","Input","HLOD","Physics",
	"WorldPartition","Events","Cooking","DataLayers","Pawn"))
class CHARNELHOUSE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Player)
	UPlayerProperties* PlayerProperties;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Player)
	class UInputActions* InputActions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyJumpApex() override;
	virtual void Landed(const FHitResult& Hit) override;
	
	void AddMappingContext(const UInputMappingContext* Context,int Priority) const;
	void Error(FString Message);

	// BINDINGS //
	void OnMove(const FInputActionValue& Value);
	void OnSprintStart(const FInputActionValue& Value);
	void OnSprintEnd(const FInputActionValue& Value);
	void UpdateCameraRotation(const FInputActionValue& Value);
	void OnJump(const FInputActionValue& Value);
};
