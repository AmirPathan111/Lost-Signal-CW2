// Fill out your copyright notice in the Description page of Project Settings.


#include "SimonSays.h"
// Sets default values
ASimonSays::ASimonSays()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ASimonSays::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASimonSays::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// void ASimonSays::showColours()
// {
// 	for (selectableColours colour : ColourOrder[currentStage].colours) //Loops around each colour for the stage the player is current on
// 	{
// 		switch (colour) //Shows the specific colour on the player's screen in the order the player must reply back to 
// 		{
// 		case Red:
// 			showThisColour(selectableColours::Red);
// 			break;
// 		case Green:
// 			showThisColour(selectableColours::Green);
// 			break;
// 		case Blue:
// 			showThisColour(selectableColours::Blue);
// 			break;
// 		case Yellow:
// 			showThisColour(selectableColours::Yellow);
// 			break;
// 		}
// 	}
// }

void ASimonSays::colourPressed(selectableColours selectedColour)
{
	if (selectedColour == ColourOrder[currentStage].colours[index]) //If the player clicks the correct colour
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Correct");
		index++;
	}
	else //Player failed
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Wrong");
		index = 0;
		currentStage = 0;
		puzzleCompletedEvent(false); //Resets the puzzle
	}

	if (index >=  ColourOrder[currentStage].colours.Num()) //When player Completes a stage of the puzzle
	{
		if (currentStage+1 < ColourOrder.Num()) //If the player still has stages to complete
		{
			currentStage++;
			index = 0;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Part Completed");
			puzzleCompletedEvent(false); //Shows the next colours in the blueprint
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Puzzle Completed");
			puzzleCompletedEvent(true); //Triggers a blueprint that opens a door or something
		}
	}
}
