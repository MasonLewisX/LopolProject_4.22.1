// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <LopolProject.h>
#include <BehaviorTree/BehaviorTree.h>
#include <BehaviorTree/BehaviorTreeComponent.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <BehaviorTree/Blackboard/BlackboardKeyAllTypes.h>
#include <LopolProjectCharacter.h>
#include "LopolAIController.generated.h"

/**
 * 
 */
UCLASS()
class LOPOLPROJECT_API ALopolAIController : public AAIController
{
	GENERATED_BODY()


public:
	ALopolAIController(const class FObjectInitializer & ObjectInitializer);

	virtual void Possess(APawn* InPawn) override;

//	void(SetEnemy(class APawn* InPawn));
	














private:
	UPROPERTY(transient)
		UBlackboardComponent* BlackboardComp;

	UPROPERTY(transient)
		UBehaviorTreeComponent* BehaviorComp;


protected:
//	int32 EnemyKeyID;






};
