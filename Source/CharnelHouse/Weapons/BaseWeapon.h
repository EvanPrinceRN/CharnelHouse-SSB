// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharnelHouse/Data/CharnelStructs.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class CHARNELHOUSE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* WeaponsDataTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName WeaponName;
	UPROPERTY(BlueprintReadWrite)
	AActor* OwnerActor;
	UPROPERTY(BlueprintReadWrite)
	bool IsAttacking;
protected:
	FWeaponData* WeaponData;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintPure)
	void GetWeaponData(FWeaponData& Data);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
