// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "SimonSays.generated.h"


UENUM(BlueprintType) //Enum that stores the puzzle that the simon says class will use https://www.youtube.com/watch?v=vJr1h-80mEM
enum selectableColours : uint8 
{
	Red		UMETA(DisplayName = "Red"),
	Green	UMETA(DisplayName = "Green"),
	Blue	UMETA(DisplayName = "Blue"),
	Yellow	UMETA(DisplayName = "Yellow"),
};

USTRUCT(BlueprintType) //Structure that stores a list of colours the terminal will show
struct FColourOrder
{
	GENERATED_BODY()
public:
	UPROPERTY(editanywhere, BlueprintReadWrite, Category="Puzzle")
	TArray<TEnumAsByte<selectableColours>> colours;
	
};

UCLASS() //Main Class
class MYPROJECT2_API ASimonSays : public AActor
{
	GENERATED_BODY()
	
public:
	//Array that stores the orders that the terminal will show the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle")
	TArray<FColourOrder> ColourOrder;
	// Sets default values for this actor's properties
	ASimonSays();
	UFUNCTION(BlueprintCallable, Category = "Puzzle")
	void colourPressed(selectableColours colour); //Function that runs when player presses a coloured button
	//UFUNCTION(BlueprintCallable, Category = "Puzzle") //Function that starts the puzzle
	//void showColours();
	UFUNCTION(BlueprintImplementableEvent, Category = "Puzzle")
	void puzzleCompletedEvent();
	//UFUNCTION(BlueprintImplementableEvent, Category="Puzzle")
	//void showThisColour(selectableColours colour);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int32 index = 0; //Index of what buttons the player is currently at (So if in green, pink, red and player picks green and pink then player is at index 2 and needs to find index 2 aka red)
	int32 currentStage =0; //Current stage the player is in 

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
