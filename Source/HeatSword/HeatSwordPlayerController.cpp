// Fill out your copyright notice in the Description page of Project Settings.


#include "HeatSwordPlayerController.h"

void AHeatSwordPlayerController::SetPlayerEnabledState(bool SetPlayerEnabled)
{
	if (SetPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
		AHeatSwordPlayerController::bShowMouseCursor = true;
	}

	else
	{
		GetPawn()->DisableInput(this);
		AHeatSwordPlayerController::bShowMouseCursor = false;
	}
}