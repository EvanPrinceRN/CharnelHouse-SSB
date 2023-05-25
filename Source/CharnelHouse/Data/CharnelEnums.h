// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharnelEnums.generated.h"

UENUM(BlueprintType)
enum EAttackType
{
	AT_None	 UMETA(DisplayName = "None"),
	AT_Light UMETA(DisplayName = "Light"),
	AT_Heavy UMETA(DisplayName = "Heavy")
};

UCLASS()
class CHARNELHOUSE_API UCharnelEnums : public UObject
{
	GENERATED_BODY()
};
