// 


#include "GSUIHitExecutionCalculation.h"

#include "AbilitySystemComponent.h"
#include "Characters/Heroes/GSHeroCharacter.h"
#include "GameFramework/PlayerState.h"
#include "Player/GSPlayerController.h"

void UGSUIHitExecutionCalculation::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	UAbilitySystemComponent* AbilitySystemComponent = ExecutionParams.GetSourceAbilitySystemComponent();
	if (!IsValid(AbilitySystemComponent))
	{
		return;
	}
	
	AActor* _Owner = AbilitySystemComponent->GetOwner();
	if (!IsValid(_Owner))
	{
		return;
	}
	
	auto* PlayerState = Cast<APlayerState>(_Owner);
	if (!IsValid(PlayerState))
	{
		return;
	}
	
	APlayerController* PC = PlayerState->GetPlayerController();
	auto* CastedPC = Cast<AGSPlayerController>(PC);
	if (!IsValid(CastedPC))
	{
		return;
	}
	
	APawn* Pawn = PC->GetPawn();
	if (!IsValid(Pawn))
	{
		return;
	}
	
	auto* Hero = Cast<AGSHeroCharacter>(Pawn);
	if (!IsValid(Hero))
	{
		return;
	}
	
	CastedPC->SetHitImpactForReticle();
}
