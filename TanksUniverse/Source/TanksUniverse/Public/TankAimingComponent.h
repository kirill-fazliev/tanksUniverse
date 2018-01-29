// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKSUNIVERSE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()


public:	
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* Barrel);
	void SetTurretReference(UTankTurret* Turret);

	// Called every frame
	void AimAt(FVector, float);


private:

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector);
};
