// Fill out your copyright notice in the Description page of Project Settings.


#include "SimonSays.h"

// Sets default values
ASimonSays::ASimonSays()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

void ASimonSays::colourPressed(int32 colour)
{
	/*for (TArray Arrays : puzzleOrder)
	{
		for (int32 number : Arrays)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Number?? %d"), number));
		}
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "New Line");

	}*/
}

