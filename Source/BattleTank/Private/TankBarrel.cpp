// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	RawNewElevation = FMath::Clamp(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}
