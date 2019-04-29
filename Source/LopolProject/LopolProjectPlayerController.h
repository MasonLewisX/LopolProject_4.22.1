// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "LopolProjectPlayerController.generated.h"





/**	
 * 
 */
UCLASS()
class LOPOLPROJECT_API ALopolProjectPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	ALopolProjectPlayerController();

	
protected:
	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
//	virtual void SetupInputComponent() override;
	// End PlayerController interface

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	/** Navigate player to the current touch location. */
//	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Navigate player to the given world location. */
//	void SetNewMoveDestination(const FVector DestLocation);



protected:
	
	/** Handler for when a touch input begins. */
	UFUNCTION(BlueprintCallable, Category = "Touch Input")
	void TotalControlFunction(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handler for when a touch input stops. */
	//UFUNCTION(BlueprintCallable, Category = "Touch Input")
	//void TouchRealsed(ETouchIndex::Type FingerIndex, FVector Location);



};
