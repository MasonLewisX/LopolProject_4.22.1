// Fill out your copyright notice in the Description page of Project Settings.

#include "Trap_Alligator.h"
#include <Engine.h>
#include <CoreUObject.h>
#include <Runtime/CoreUObject/Public/UObject/UObjectGlobals.h>

// Sets default values
ATrap_Alligator::ATrap_Alligator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Alligator = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Alligators"));

}

// Called when the game starts or when spawned
void ATrap_Alligator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrap_Alligator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);





}

