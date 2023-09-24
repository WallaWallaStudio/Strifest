// 

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GSUIHitExecutionCalculation.generated.h"

UCLASS()
class GASSHOOTER_API UGSUIHitExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;;
};
