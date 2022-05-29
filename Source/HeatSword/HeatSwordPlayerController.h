// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HeatSwordPlayerController.generated.h"

UCLASS()
class HEATSWORD_API AHeatSwordPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void SetPlayerEnabledState(bool SetPlayerEnabled);
};
