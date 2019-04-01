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
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ALopolProjectPlayerController::TotalControlFunction); // 여기서 마지막 인스턴스(?)에 이 터치 바인드가 작동되게 하도록 하는 내가 컨스트럭션 한 함수임.
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
	GetHitResultUnderFinger(ETouchIndex::Touch1, ECC_Camera, true, TouchedResult); // 정상 작동 되는건데 여기서 안됨.
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


	GEngine->AddOnScreenDebugMessage(-1, 0.001f, FColor::Red, TouchCheckDisplay); // 정상 작동 됨. 터치 눌렀을때만.



}
*/



// 터치 인풋 관련 쪽에 문제 있는걸로 추정. 바로 요 아래.
// 이거 잘못된거 맞음.
void ALopolProjectPlayerController::TotalControlFunction(const ETouchIndex::Type FingerIndex, const FVector Location) // (언리얼 샘플 예제)
{

	// GetHitResultUnderFingerByChannel(ETouchIndex::Touch1, TraceTypeQuery1, true, TouchedResult);  //  뭘 써야 하지? // 이거 아닌듯.

//	ALopolProjectCharacter* ProjectCharacter = Cast<ALopolProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
//	ALopolPlayerCharacter* PlayerCharacter = Cast<ALopolPlayerCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
//	ALopolEnemyCharacter* EnemyCharacter = Cast<ALopolEnemyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	
	GetHitResultUnderFinger(ETouchIndex::Touch1, ECC_Camera, true, TouchedResult); // 정상 작동 됨.
	
	ALopolProjectCharacter* TouchedCharacter = Cast<ALopolProjectCharacter>(TouchedResult.Actor);  // 정상 작동 됨.
	ALopolPlayerCharacter* TouchedPlayer = Cast<ALopolPlayerCharacter>(TouchedCharacter); // 정상 작동 됨.
	ALopolEnemyCharacter* TouchedEnemy = Cast<ALopolEnemyCharacter>(TouchedCharacter); // 정상 작동 됨.

	/*
	ProjectCharacter = TouchedActor;
	TouchedPlayer = PlayerCharacter;
	TouchedEnemy = EnemyCharacter;
	*/

	/*
	if (ProjectCharacter->IsCharacterSelected() == false && !TouchedActor) // 이거 안됨. 왜?  //////////////////////////////////////////////////////////////////////////////////////////////
	{
		PlayerCharacter->SetIsCharacterSelected(false);
		//bCheckCharacterSelected = PlayerCharacterReference->IsCharacterSelected();
		TouchCheckDisplay = UKismetStringLibrary::Conv_VectorToString(TouchedResult.Location);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TouchCheckDisplay);
	}*/

	/*
	if (PlayerCharacter->IsCharacterSelected() == true && !TouchedActor) // 이거 안됨. 왜?			//////////////////////////////////////////////////////////////
	{
		
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, TouchedResult.Location);
		//PlayerCharacterReference->GetController()
	}*/

	if (TouchedPlayer) // 플레이어 캐릭터가 터치 됐을 때					// 정상 작동.
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
		

	if (TouchedEnemy) // 강제종료. (다른건 다 정상인데 이거만 누르면 튕김.) // 이제 됨!!
	{
		TouchedEnemy->SetIsCharacterSelected(true); // 정상 작동 됨.
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
	if (PlayerCharacter->IsCharacterSelected() == true && EnemyCharacter) // 강제종료. (다른건 다 정상인데 이거만 누르면 튕김.)
	{

		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, EnemyCharacter->GetActorLocation());
		

	}*/

	





	/*
	FVector HitLocation;
	HitLocation = TouchedResult.Location;
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, HitLocation); // 이 코드 라인이 문제. 가져올 수는 있는데, 그 가져온게 정의가 되어있지 않다.
	*/

	
	
	
	if(!TouchedCharacter)
	{
	//	ProjectCharacter->SetIsCharacterSelected(false);
		//bCheckCharacterSelected = PlayerCharacterReference->IsCharacterSelected();
		TouchCheckDisplay = UKismetStringLibrary::Conv_VectorToString(TouchedResult.Location);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TouchCheckDisplay);
	}
	

	/*
	if(!TouchedPlayerCharacter) // 이거 팅김
	{
		TouchedPlayerCharacter->ALopolProjectCharacter::SetIsCharacterSelected(false);
	}
	*/
	
	// 이 줄이 문제. 였음.
	//bCheckCharacterSelected = TouchedPlayerCharacter->IsCharacterSelected(); // 여기 오픈하니 팅김. 캐릭터 클릭했을땐 되는데, 다른데 클릭하면 안됨. 이유가 뭐지?

	//TouchCheckDisplay = UKismetStringLibrary::Conv_BoolToString(bCheckCharacterSelected); // 이거 문제는 아닌듯.



	if (TouchedResult.Actor == nullptr)
	{

	}












	
	// Jump();

}






bool ALopolProjectPlayerController::CheckCharacterSelected() // 얘 정상 작동 됨.
{
	return bCheckCharacterSelected;  //정상 작동.
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
		if (IsDoubleTouched == true) // 앞에서 Hit Result의 Actor 값을 PlayerCharacter로 Cast to 한 후에 그 Reference 값을 가져와서 써야됨.
		{
			
		}
	}

	else
	{

	}
}

*/




