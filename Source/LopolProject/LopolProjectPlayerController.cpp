// Fill out your copyright notice in the Description page of Project Settings.

#include "LopolProjectPlayerController.h"
#include <LopolPlayerCharacter.h>
#include <LopolEnemyCharacter.h>
#include <LopolProjectCharacter.h>
#include <Engine.h>
#include <AIModule.h>
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

/*
void ALopolProjectPlayerController::SetupInputComponent()
{
	// ** set up gameplay key bindings **
	Super::SetupInputComponent();

//	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ALopolProjectPlayerController::OnSetDestinationPressed);
//	InputComponent->BindAction("SetDestination", IE_Released, this, &ALopolProjectPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ALopolProjectPlayerController::TotalControlFunction); // ���⼭ ������ �ν��Ͻ�(?)�� �� ��ġ ���ε尡 �۵��ǰ� �ϵ��� �ϴ� ���� ����Ʈ���� �� �Լ���.
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ALopolProjectPlayerController::TotalControlFunction);

//	InputComponent->BindAction("ResetVR", IE_Pressed, this, &ALopolProjectPlayerController::OnResetVR);
}*/



void ALopolProjectPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

//	TouchCheckDisplay = UKismetStringLibrary::Conv_BoolToString(bCheckCharacterSelected);
//	GEngine->AddOnScreenDebugMessage(-1, 0.001f, FColor::Green, TouchCheckDisplay);

}

/*
void ALopolProjectPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	GetHitResultUnderFinger(ETouchIndex::Touch1, ECC_Camera, true, TouchedResult); // ���� �۵� �Ǵ°ǵ� ���⼭ �ȵ�.
//	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, TouchedResult);


//	if (HitResult.bBlockingHit)
//	{
		// We hit something, move there
//		SetNewMoveDestination(HitResult.ImpactPoint);
//	}
}*/




/*
void ALopolProjectPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	GEngine->AddOnScreenDebugMessage(-1, 0.001f, FColor::Red, TouchCheckDisplay); // ���� �۵� ��. ��ġ ����������.



}
*/



// ��ġ ��ǲ ���� �ʿ� ���� �ִ°ɷ� ����. �ٷ� �� �Ʒ�.
// �̰� �߸��Ȱ� ����.
void ALopolProjectPlayerController::TotalControlFunction(const ETouchIndex::Type FingerIndex, const FVector Location) // (�𸮾� ���� ����)
{

	// GetHitResultUnderFingerByChannel(ETouchIndex::Touch1, TraceTypeQuery1, true, TouchedResult);  //  �� ��� ����? // �̰� �ƴѵ�.

//	ALopolProjectCharacter* ProjectCharacter = Cast<ALopolProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
//	ALopolPlayerCharacter* PlayerCharacter = Cast<ALopolPlayerCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
//	ALopolEnemyCharacter* EnemyCharacter = Cast<ALopolEnemyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	
	GetHitResultUnderFinger(ETouchIndex::Touch1, ECC_Camera, true, TouchedResult); // ���� �۵� ��.
	
	ALopolProjectCharacter* TouchedCharacter = Cast<ALopolProjectCharacter>(TouchedResult.Actor);  // ���� �۵� ��.
	ALopolPlayerCharacter* TouchedPlayer = Cast<ALopolPlayerCharacter>(TouchedCharacter); // ���� �۵� ��.
	ALopolEnemyCharacter* TouchedEnemy = Cast<ALopolEnemyCharacter>(TouchedCharacter); // ���� �۵� ��.

	/*
	ProjectCharacter = TouchedActor;
	TouchedPlayer = PlayerCharacter;
	TouchedEnemy = EnemyCharacter;
	*/

	/*
	if (ProjectCharacter->IsCharacterSelected() == false && !TouchedActor) // �̰� �ȵ�. ��?  //////////////////////////////////////////////////////////////////////////////////////////////
	{
		PlayerCharacter->SetIsCharacterSelected(false);
		//bCheckCharacterSelected = PlayerCharacterReference->IsCharacterSelected();
		TouchCheckDisplay = UKismetStringLibrary::Conv_VectorToString(TouchedResult.Location);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TouchCheckDisplay);
	}*/

	/*
	if (PlayerCharacter->IsCharacterSelected() == true && !TouchedActor) // �̰� �ȵ�. ��?			//////////////////////////////////////////////////////////////
	{
		
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, TouchedResult.Location);
		//PlayerCharacterReference->GetController()
	}*/

	if (TouchedPlayer) // �÷��̾� ĳ���Ͱ� ��ġ ���� ��					// ���� �۵�.
	{

		TouchedPlayer->SetIsCharacterSelected(true);
		bCheckCharacterSelected = TouchedPlayer->IsCharacterSelected();
		TouchCheckDisplay = UKismetStringLibrary::Conv_BoolToString(bCheckCharacterSelected);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TouchCheckDisplay);

			/*
			if (TouchedPlayerCharacter->IsCharacterSelected() == true )
			{
				// GetHitResultUnderFinger(ETouchIndex::Touch1, ECC_Camera, true, TouchedResultSecond);
				// ALopolProjectCharacter* TouchedActorSecond = Cast<ALopolProjectCharacter>(TouchedResultSecond.Actor);
				// ALopolProjectCharacter* TouchedEnemyCharacterSecond = Cast<ALopolEnemyCharacter>(TouchedActorSecond);
				TouchedPlayerCharacter->ALopolProjectCharacter::SetIsCharacterSelected(false);
			}*/
	}
		

	if (TouchedEnemy) // ��������. (�ٸ��� �� �����ε� �̰Ÿ� ������ ƨ��.) // ���� ��!!
	{
		TouchedEnemy->SetIsCharacterSelected(true); // ���� �۵� ��.
		bCheckCharacterSelected = TouchedEnemy->IsCharacterSelected();
		TouchCheckDisplay = UKismetStringLibrary::Conv_BoolToString(bCheckCharacterSelected);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TouchCheckDisplay);
			
		/*
		if(PlayerCharacter->IsCharacterSelected() == true)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, EnemyCharacter->GetActorLocation());
		}*/

	}

	
	
	/*
	if (PlayerCharacter->IsCharacterSelected() == true && EnemyCharacter) // ��������. (�ٸ��� �� �����ε� �̰Ÿ� ������ ƨ��.)
	{

		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, EnemyCharacter->GetActorLocation());
		

	}*/

	





	/*
	FVector HitLocation;
	HitLocation = TouchedResult.Location;
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, HitLocation); // �� �ڵ� ������ ����. ������ ���� �ִµ�, �� �����°� ���ǰ� �Ǿ����� �ʴ�.
	*/

	
	
	
	if(!TouchedCharacter)
	{
	//	ProjectCharacter->SetIsCharacterSelected(false);
		//bCheckCharacterSelected = PlayerCharacterReference->IsCharacterSelected();
		TouchCheckDisplay = UKismetStringLibrary::Conv_VectorToString(TouchedResult.Location);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TouchCheckDisplay);
	}
	

	/*
	if(!TouchedPlayerCharacter) // �̰� �ñ�
	{
		TouchedPlayerCharacter->ALopolProjectCharacter::SetIsCharacterSelected(false);
	}
	*/
	
	// �� ���� ����. ����.
	//bCheckCharacterSelected = TouchedPlayerCharacter->IsCharacterSelected(); // ���� �����ϴ� �ñ�. ĳ���� Ŭ�������� �Ǵµ�, �ٸ��� Ŭ���ϸ� �ȵ�. ������ ����?

	//TouchCheckDisplay = UKismetStringLibrary::Conv_BoolToString(bCheckCharacterSelected); // �̰� ������ �ƴѵ�.



	if (TouchedResult.Actor == nullptr)
	{

	}












	
	// Jump();

}






bool ALopolProjectPlayerController::CheckCharacterSelected() // �� ���� �۵� ��.
{
	return bCheckCharacterSelected;  //���� �۵�.
}


/*


void ALopolProjectPlayerController::TouchRealsed(ETouchIndex::Type FingerIndex, FVector Location)
{
	
	
	GetHitResultUnderFinger(ETouchIndex::Touch1, ECC_Camera, true, TouchedResult);

	ALopolProjectCharacter* TouchedActor = Cast<ALopolProjectCharacter>(TouchedResult.Actor);
	ALopolPlayerCharacter* TouchedPlayerCharacter = Cast<ALopolPlayerCharacter>(TouchedActor);
	ALopolEnemyCharacter* TouchedEnemyCharacter = Cast<ALopolEnemyCharacter>(TouchedActor);
	

	if (TouchedPlayerCharacter->IsCharacterSelected() == true)
	{
		TouchedPlayerCharacter->ALopolProjectCharacter::SetIsCharacterSelected(false);
	}

	
	
	
	// StopJumping();
}


*/












/*


void ALopolProjectPlayerController::IsDoubleTouched(bool IsDoubleTouched)
{
	if(IsDoubleTouched == true)
	{
		if (IsDoubleTouched == true) // �տ��� Hit Result�� Actor ���� PlayerCharacter�� Cast to �� �Ŀ� �� Reference ���� �����ͼ� ��ߵ�.
		{
			
		}
	}

	else
	{

	}
}

*/




