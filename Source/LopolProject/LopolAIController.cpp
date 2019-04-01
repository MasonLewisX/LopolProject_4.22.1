// Fill out your copyright notice in the Description page of Project Settings.

#include "LopolAIController.h"
#include <LopolProject.h>
#include <BehaviorTree/BehaviorTree.h>
#include <BehaviorTree/BehaviorTreeComponent.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <BehaviorTree/Blackboard/BlackboardKeyAllTypes.h>
#include <LopolProjectCharacter.h>


ALopolAIController::ALopolAIController(const FObjectInitializer& ObjectInitializer) //: Super(ObjectInitializer)
{
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	BrainComponent = BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));


}






void ALopolAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);
	/*
	ASimpleGameBot* Bot = Cast<ASimpleGameBot>(InPawn);
	if (Bot && Bot->BotBehavior)
	{
		if (Bot->BotBehavior->BlackboardAsset)
		{
			Blackboard->InitializeBlackboard(*Bot->BotBehavior->BlackboardAsset);
		}

		EnemyKeyID = BlackboardComp->GetKeyID("Enemy");
		BehaviorComp->StartTree(*(Bot->BotBehavior));
	}*/

}