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

void ASimonSays::showColours()
{
	for (selectableColours colour : ColourOrder[currentStage].colours) //Loops around each colour for the stage the player is current on
	{
		switch (colour) //Shows the specific colour on the player's screen in the order the player must reply back to 
		{
		case Red:
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Red");
			break;
		case Green:
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Green");
			break;
		case Blue:
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Blue");
			break;
		case Yellow:
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "yellow");
			break;
		}
	}
}

void ASimonSays::colourPressed(selectableColours selectedColour)
{
	if (selectedColour == ColourOrder[currentStage].colours[index]) //If the player clicks the correct colour
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Correct");
		index++;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Wrong");
		index = 0;
		currentStage = 0;
		return; //This should stop the puzzle
	}

	if (index >=  ColourOrder[currentStage].colours.Num()) //When player Completes a stage of the puzzle
	{
		if (currentStage+1 < ColourOrder.Num()) //If the player still has stages to complete
		{
			currentStage++;
			index = 0;
			showColours();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Puzzle Completed");
			puzzleCompletedEvent(); //Triggers a blueprint that opens a door or something
		}
	}
}

/*for (TArray Arrays : puzzleOrder)
{
	for (int32 number : Arrays)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Number?? %d"), number));
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "New Line");

}*/
