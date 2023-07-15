// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MathLibrary.generated.h"

UCLASS()
class CHARNELHOUSE_API UMathLibrary : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category=MATHPACKFUNCTIONS)	// Returns forward vector of a given rotation.
	static FVector GetForwardVector(FRotator Rotation);
	
	UFUNCTION(BlueprintPure, Category=MATHPACKFUNCTIONS)	// Returns right vector of a given rotation.
	static FVector GetRightVector(FRotator Rotation);			

	UFUNCTION(BlueprintPure, Category=MATHPACKFUNCTIONS)	// Returns takes a direction, multiplies it and adds it back to the location.
	static FVector IncreaseVector(FVector Direction, FVector Location, float Magnitude);
};
 