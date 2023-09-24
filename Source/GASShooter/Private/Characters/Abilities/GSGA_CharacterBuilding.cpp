// Copyright 2020 Dan Kestranek.


#include "Characters/Abilities/GSGA_CharacterBuilding.h"
#include "Characters/GSCharacterBase.h"
#include "GASShooter/GASShooter.h"

UGSGA_CharacterBuilding::UGSGA_CharacterBuilding()
{
	AbilityInputID = EGSAbilityInputID::BuildingFloor;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::NonInstanced;
	AbilityTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Building")));
	ActivationOwnedTags.RemoveTag(FGameplayTag::RequestGameplayTag("Ability.BlocksInteraction"));
}

void UGSGA_CharacterBuilding::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
}

bool UGSGA_CharacterBuilding::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	return true;
}

void UGSGA_CharacterBuilding::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	if (ActorInfo != NULL && ActorInfo->AvatarActor != NULL)
	{
		CancelAbility(Handle, ActorInfo, ActivationInfo, true);
	}
}

void UGSGA_CharacterBuilding::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
}
