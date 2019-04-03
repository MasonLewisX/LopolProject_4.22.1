// Fill out your copyright notice in the Description page of Project Settings.

#include "BuffSkill.h"

// Sets default values
ABuffSkill::ABuffSkill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuffSkill::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuffSkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

