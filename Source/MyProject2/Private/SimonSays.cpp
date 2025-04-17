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

void ASimonSays::colourPressed(selectableColours colour)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "New Line");
		switch (colour) //What colour is clicked
		{
		case Red:
			GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,"ColourPressed");
			break;
		case Green:
			GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Green,"ColourPressed");
			break;
		case Blue:
			GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Blue,"ColourPressed");
			break;
		case Yellow:
			GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Yellow,"ColourPressed");
			break;
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
}

