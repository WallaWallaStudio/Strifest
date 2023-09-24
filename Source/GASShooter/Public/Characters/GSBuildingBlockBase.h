// Copyright 2020 Dan Kestranek.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GSASCActorBase.h"
#include "GSBuildingBlockBase.generated.h"

UCLASS()
class GASSHOOTER_API AGSBuildingBlockBase : public AGSASCActorBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGSBuildingBlockBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void InitializeAttributes();


	// Reference to the AttributeSetBase. It will live on the PlayerState or here if the character doesn't have a PlayerState.
	UPROPERTY()
	class UGSAttributeSetBase* AttributeSetBase;

	// Default attributes for a character for initializing on spawn/respawn.
	// This is an instant GE that overrides the values for attributes that get reset on spawn/respawn.
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GASShooter|Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
