// Fill out your copyright notice in the Description page of Project Settings.
#include "SpawnSkill.h"
#include <Engine.h>
// #include <SimpleGameCharacter.h>
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/KismetStringLibrary.h>
// Sets default values
ASpawnSkill::ASpawnSkill()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}
// Called when the game starts or when spawned
void ASpawnSkill::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void ASpawnSkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}