// Fill out your copyright notice in the Description page of Project Settings.
#include "TankTurret.h"
#include "TanksUniverse.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	auto relativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = relativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}