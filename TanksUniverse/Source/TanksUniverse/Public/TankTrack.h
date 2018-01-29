// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply foreces to tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKSUNIVERSE_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Max force per Track in newtton
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; // 40 tonne tank
};
