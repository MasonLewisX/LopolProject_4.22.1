// Fill out your copyright notice in the Description page of Project Settings.

#include "LopolEnemyCharacter.h"



ALopolEnemyCharacter::ALopolEnemyCharacter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;




}
// Called when the game starts or when spawned









void ALopolEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	SetIsEnemy(true);

}



void ALopolEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


/*


void ALopolEnemyCharacter::SetIsEnemy(bool IsEnemy)
{
	bIsEnemy = IsEnemy;
}

bool ALopolEnemyCharacter::IsEnemy()
{
	return bIsEnemy;
}


*/