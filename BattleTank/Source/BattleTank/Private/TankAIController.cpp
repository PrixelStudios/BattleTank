// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Player Controller not possessing a tank"));
	} 
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Player Controller possesing : %s"), *ControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find find the player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player"));
	}


}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	} 
	
	return Cast<ATank>(PlayerPawn);
	
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank> (GetPawn());
}


