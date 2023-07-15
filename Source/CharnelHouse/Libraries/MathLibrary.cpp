// Fill out your copyright notice in the Description page of Project Settings.

#include "MathLibrary.h"

FVector UMathLibrary::GetForwardVector( FRotator Rotation )
{
	return Rotation.Vector();
}

FVector UMathLibrary::GetRightVector( FRotator Rotation )
{
	return FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
}

FVector UMathLibrary::IncreaseVector( FVector Direction, FVector Location, float Magnitude )
{
	return (Direction*Magnitude) + Location;
}
