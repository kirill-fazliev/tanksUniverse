// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKSUNIVERSE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()


public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	// Called every frame
	void AimAt(FVector);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;


private:
	UTankAimingComponent();

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	void BeginPlay() override;

	void MoveBarrelTowards(FVector);

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluepint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ReloadTimeInSeconds = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 RoundsLeft = 3;

	double LastFireTime = 0.0;
	bool IsBarrelMoving();
	FVector AimDirection;

};
