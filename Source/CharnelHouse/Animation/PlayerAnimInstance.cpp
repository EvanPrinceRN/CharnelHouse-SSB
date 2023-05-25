// Fill out your copyright notice in the Description page of Project Settings.


#include "CharnelHouse/Animation/PlayerAnimInstance.h"

#include "CharnelHouse/Characters/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(APlayerCharacter*Player = Cast<APlayerCharacter>(TryGetPawnOwner()))
	{
		Speed = FVector(Player->GetVelocity().X,Player->GetVelocity().Y,0).Length();
		Jumping = Player->GetCharacterMovement()->IsMovingOnGround()?false:true;
		Falling = Player->GetVelocity().Z<-5;
	}
}
