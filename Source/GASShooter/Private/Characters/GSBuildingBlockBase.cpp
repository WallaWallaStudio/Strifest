// Copyright 2020 Dan Kestranek.


#include "Characters/GSBuildingBlockBase.h"
#include "Player/GSPlayerController.h"
#include "Player/GSPlayerState.h"
#include "Characters/Abilities/GSAbilitySystemComponent.h"

// Sets default values
AGSBuildingBlockBase::AGSBuildingBlockBase()
	: Super()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AbilitySystemComponent = CreateDefaultSubobject<UGSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	//AbilitySystemComponent->SetIsReplicated(true);

	// Mixed mode means we only are replicated the GEs to ourself, not the GEs to simulated proxies. If another GDPlayerState (Hero) receives a GE,
	// we won't be told about it by the Server. Attributes, GameplayTags, and GameplayCues will still replicate to us.
	//AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// AI won't have PlayerControllers so we can init again here just to be sure. No harm in initing twice for heroes that have PlayerControllers.
	//GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);

	AttributeSetBase = CreateDefaultSubobject<UGSAttributeSetBase>(TEXT("AttributeSetBase"));


}

// Called when the game starts or when spawned
void AGSBuildingBlockBase::BeginPlay()
{
	Super::BeginPlay();

	InitializeAttributes();
	//AddCharacterAbilities();
}

// Called every frame
void AGSBuildingBlockBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGSBuildingBlockBase::InitializeAttributes()
{
	if (!IsValid(AbilitySystemComponent))
	{
		return;
	}

	if (!DefaultAttributes)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Missing DefaultAttributes for %s. Please fill in the character's Blueprint."), *FString(__FUNCTION__), *GetName());
		return;
	}

	// Can run on Server and Client
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributes, 1, EffectContext);
	if (NewHandle.IsValid())
	{
		FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*NewHandle.Data.Get());
	}
}

