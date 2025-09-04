// Made by Steven Kearney

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CoreMinimal.h"
#include "BaseAIController.generated.h"


/**
 * 
 */
UCLASS()
class LDP_API ABaseAIController : public AAIController
{
	GENERATED_BODY()


protected:

	UFUNCTION(BlueprintCallable)
	void OnPossesComplete();

	FGenericTeamId TeamId;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

public:
	UPROPERTY(BlueprintReadWrite)
	class ABaseCharacter* Agent;

	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
};
