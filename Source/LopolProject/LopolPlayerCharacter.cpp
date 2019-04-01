// Fill out your copyright notice in the Description page of Project Settings.

#include "LopolPlayerCharacter.h"



ALopolPlayerCharacter::ALopolPlayerCharacter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;




}
// Called when the game starts or when spawned







void ALopolPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	SetIsEnemy(false);

}


void ALopolPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}









/*
void ALopolPlayerCharacter::SetIsEnemy(bool IsEnemy)
{
	bIsEnemy = IsEnemy;
}

bool ALopolPlayerCharacter::IsEnemy()
{
	return bIsEnemy;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ALopolPlayerCharacter::SetDoesCharacterSelected(bool DoesSelected)
{
	bDoesCharacterSelected = DoesSelected;

}

bool ALopolPlayerCharacter::DoesCharacterSelected()
{
	return  bDoesCharacterSelected;

}*/