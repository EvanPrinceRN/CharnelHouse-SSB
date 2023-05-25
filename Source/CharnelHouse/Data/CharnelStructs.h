// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharnelEnums.h"
#include "Engine/DataTable.h"
#include "UObject/Object.h"
#include "CharnelStructs.generated.h"

USTRUCT(BlueprintType)
struct FAttackData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* AttackMontage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackSize = 15;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackDamage = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EAttackType> AttackType;
};

USTRUCT(BlueprintType)
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* WeaponMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAttackData> LightAttacks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAttackData> HeavyAttacks;
};

UCLASS()
class CHARNELHOUSE_API UCharnelStructs : public UObject
{
	GENERATED_BODY()
};
