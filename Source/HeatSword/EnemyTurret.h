// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "EnemyTurret.generated.h"

class AHeatSwordCharacter;

UCLASS()
class HEATSWORD_API AEnemyTurret : public APawnBase
{
	GENERATED_BODY()
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called when the game starts or when spawned

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRate = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRange = 500.0f;

	AHeatSwordCharacter* PlayerPawn;
	FTimerHandle FireRateTimerHandle;

	void CheckFireCondition();

	float ReturnDistanceToPlayer();

protected:
	virtual void BeginPlay() override;

	virtual void HandleDestruction() override;
};