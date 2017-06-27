// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "EnergyExcess.h"
#include "EnergyExcessGameMode.h"
#include "EnergyExcessPlayerController.h"
#include "EnergyExcessCharacter.h"

AEnergyExcessGameMode::AEnergyExcessGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AEnergyExcessPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}