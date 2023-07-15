// Fill out your copyright notice in the Description page of Project Settings.


#include "CharnelHouse/Animation/CharnelAnimInstance.h"

#include "CharnelHouse/Characters/PlayerCharacter.h"

void UCharnelAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	Player = Cast<APlayerCharacter>(TryGetPawnOwner());
}

void UCharnelAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}
