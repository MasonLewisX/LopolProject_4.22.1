// Fill out your copyright notice in the Description page of Project Settings.

#include "LopolProjectPlayerController.h"

#include <Components/InputComponent.h>
#include <Blueprint/AIBlueprintHelperLibrary.h>
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/KismetStringLibrary.h>



ALopolProjectPlayerController::ALopolProjectPlayerController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

void ALopolProjectPlayerController::BeginPlay()
{
	Super::BeginPlay();




}




void ALopolProjectPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

//	TouchCheckDisplay = UKismetStringLibrary::Conv_BoolToString(bCheckCharacterSelected);
//	GEngine->AddOnScreenDebugMessage(-1, 0.001f, FColor::Green, TouchCheckDisplay);

}




