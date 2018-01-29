// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"
/**
 * 
 */

class ATank;
UCLASS()
class TANKSUNIVERSE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATank * GetControlledTank() const;
	void BeginPlay() override;
	void Tick(float) override;
private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocaton = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocaton = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector ScreenLocation, FVector& LookDirection) const;

};
