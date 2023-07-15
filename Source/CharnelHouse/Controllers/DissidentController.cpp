// Fill out your copyright notice in the Description page of Project Settings.


#include "CharnelHouse/Controllers/DissidentController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "CharnelHouse/Characters/Dissident.h"
#include "CharnelHouse/Data/InputDataAsset.h"

void ADissidentController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	Dissident = Cast<ADissident>(InPawn);
	if(Dissident && InputActions)
	{
		TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent = Cast<UEnhancedInputComponent>(InPawn->InputComponent);
		TObjectPtr<UEnhancedInputLocalPlayerSubsystem> Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		if(EnhancedInputComponent && Subsystem)
		{
			Subsystem->AddMappingContext(CharacterMappingContext,0);
			EnhancedInputComponent->BindAction(InputActions->Movement,ETriggerEvent::Triggered,ToRawPtr(Dissident),&APlayerCharacter::Move);
			EnhancedInputComponent->BindAction(InputActions->Camera,ETriggerEvent::Triggered,ToRawPtr(Dissident),&APlayerCharacter::CameraControl);
			EnhancedInputComponent->BindAction(InputActions->Sprint,ETriggerEvent::Triggered,ToRawPtr(Dissident),&APlayerCharacter::BeginSprint);
			EnhancedInputComponent->BindAction(InputActions->Sprint,ETriggerEvent::Completed,ToRawPtr(Dissident),&APlayerCharacter::BeginSprint);
			EnhancedInputComponent->BindAction(InputActions->Dodge,ETriggerEvent::Triggered,ToRawPtr(Dissident),&APlayerCharacter::Dodge);
		}
	}
}