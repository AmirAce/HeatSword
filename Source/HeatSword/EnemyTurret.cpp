// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTurret.h"

#include "EnemyTurret.h"
#include "Kismet/GameplayStatics.h"
#include "HeatSwordCharacter.h"

// Called when the game starts or when spawned
void AEnemyTurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &AEnemyTurret::CheckFireCondition, FireRate, true, false);

    PlayerPawn = Cast<AHeatSwordCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void AEnemyTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!PlayerPawn || ReturnDistanceToPlayer() > 2 * FireRange)
    {
        return;
    }

    RotateTurret(PlayerPawn->GetActorLocation());
}

void AEnemyTurret::CheckFireCondition()
{
    // If Player == null || is Dead THEN BAIL!!
    if (!PlayerPawn || !PlayerPawn->GetPlayerAlive())
    {
        return;
    }
    // If Player Player IS in range THEN FIRE!!!
    if (ReturnDistanceToPlayer() <= FireRange)
    {
        Fire();
    }
}

float AEnemyTurret::ReturnDistanceToPlayer()
{
    // Check if we have a valid reference to the player.
    if (!PlayerPawn)
    {
        return 0.0f;
    }

    float Distance = (PlayerPawn->GetActorLocation() - GetActorLocation()).Size();
    return Distance;
}

void AEnemyTurret::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}