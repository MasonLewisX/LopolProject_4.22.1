// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LopolProjectCharacter.h"
#include "LopolPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class LOPOLPROJECT_API ALopolPlayerCharacter : public ALopolProjectCharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	ALopolPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;






	/*



protected:

	UFUNCTION(BlueprintCallable, Category = "EnemyProperty")
		void SetIsEnemy(bool IsEnemy);

	UFUNCTION(BlueprintPure, Category = "EnemyProperty")
		bool IsEnemy();

	bool bIsEnemy;



	UFUNCTION(BlueprintCallable, Category = "SelectingCharacter")
		void SetDoesCharacterSelected(bool DoesSelected);

	UFUNCTION(BlueprintPure, Category = "SelectingCharacter")
	bool DoesCharacterSelected();

	bool bDoesCharacterSelected;




	*/
};
