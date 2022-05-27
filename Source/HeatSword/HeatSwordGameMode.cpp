// Copyright Epic Games, Inc. All Rights Reserved.

#include "HeatSwordGameMode.h"
#include "HeatSwordCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHeatSwordGameMode::AHeatSwordGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
