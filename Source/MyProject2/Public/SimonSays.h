// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimonSays.generated.h"


UCLASS()
class MYPROJECT2_API ASimonSays : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimonSays();
	UFUNCTION(BlueprintCallable, Category = "Puzzle")
	void colourPressed(int32 colour);
	//UPROPERTY(EditAnywhere, Category = "PuzzleSelect")
	//TArray<TArray<int32>> puzzleOrder;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
