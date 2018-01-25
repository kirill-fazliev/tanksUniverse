// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKSUNIVERSE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	void BeginPlay() override;
	void Tick(float) override;


private :
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
};