// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"
UCLASS()
class TANKSUNIVERSE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	void BeginPlay() override;
	void SetPawn(APawn* InPawn) override;
	void Tick(float) override;
	UFUNCTION()
	void OnPossedTankDeath();
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 80000.0;

private :
};
