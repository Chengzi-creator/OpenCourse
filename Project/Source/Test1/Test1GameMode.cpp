// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test1GameMode.h"
#include "Test1Character.h"
#include "UObject/ConstructorHelpers.h"

ATest1GameMode::ATest1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
