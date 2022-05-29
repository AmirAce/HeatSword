// Copyright Epic Games, Inc. All Rights Reserved.

#include "HeatSwordGameMode.h"
#include "HeatSwordCharacter.h"
#include "EnemyTurret.h"
#include "Kismet/GameplayStatics.h"
#include "HeatSwordPlayerController.h"
#include "UObject/ConstructorHelpers.h"

AHeatSwordGameMode::AHeatSwordGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	/*if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
}

void AHeatSwordGameMode::BeginPlay()
{
	Super::BeginPlay();

	TargetEnemies = GetTargetTurretCount();
	player = Cast<AHeatSwordCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	PlayerControllerRef = Cast<AHeatSwordPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	HandleGameStart();
	// win/lose conditions
	// Call HandleGameStart to initialize the start countdown, turret activation, pawn check, etc.

}

void AHeatSwordGameMode::ActorDied(AActor* DeadActor)
{
	//check what type of actor died, if turret, tally. If player-> lose condition.
	if (DeadActor == player)
	{
		// Handle player destruction
		//player->HandleD();
		HandleGameOver(false);

		if (PlayerControllerRef)
		{
			PlayerControllerRef->SetPlayerEnabledState(false);
		}
	}

	else if (AEnemyTurret* DestroyedTurret = Cast<AEnemyTurret>(DeadActor))
	{
		DestroyedTurret->PawnDestroyed();
		TargetEnemies--;
		if (TargetEnemies == 0)
		{
			// Add points here
			//HandleGameOver(true);
		}
	}
}

void AHeatSwordGameMode::HandleGameStart()
{
	if (PlayerControllerRef)
	{
		PlayerControllerRef->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableHandle;
		FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(PlayerControllerRef, &AHeatSwordPlayerController::SetPlayerEnabledState, true);
		GetWorldTimerManager().SetTimer(PlayerEnableHandle, PlayerEnableDelegate, StartDelay, false);
	}
}

void AHeatSwordGameMode::HandleGameOver(bool PlayerWon)
{
	//See if the player has made it to the end, show win result
	//OR lose result if player died
	//Call GameOver

}

int32 AHeatSwordGameMode::GetTargetTurretCount()
{
	TSubclassOf<AEnemyTurret> ClassToFind;

	ClassToFind = AEnemyTurret::StaticClass();

	TArray<AActor*> EnemyActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, EnemyActors);

	UE_LOG(LogTemp, Warning, TEXT("%i enemies left"), EnemyActors.Num());
	return EnemyActors.Num();

}
