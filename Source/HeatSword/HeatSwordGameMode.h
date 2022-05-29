// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HeatSwordGameMode.generated.h"

class AHeatSwordCharacter;
class AEnemyTurret;
class AHeatSwordPlayerController;

UCLASS(minimalapi)
class AHeatSwordGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHeatSwordGameMode();
	void ActorDied(AActor* DeadActor);

	void BeginPlay() override;

private:
	int32 TargetEnemies = 0;
	int32 GetTargetTurretCount();
	AHeatSwordPlayerController* PlayerControllerRef;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = "true"));
	AHeatSwordCharacter* player;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Loop", meta = (AllowPrivateAccess = "true"));
	int StartDelay = 3;

	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);
};



