#include "BaseAIController.h"
#include "BaseCharacter.h"

void ABaseAIController::OnPossesComplete() {
	ABaseCharacter* Chr = Cast<ABaseCharacter>(GetPawn());
	if (Chr) {
		Agent = Chr;
		TeamId = FGenericTeamId(Agent->TeamID);
	}
}

ETeamAttitude::Type ABaseAIController::GetTeamAttitudeTowards(const AActor& Other) const {
	//Check if Pawn
	const APawn* OtherPawn = Cast<APawn>(&Other);
	if(OtherPawn == nullptr)
	{
		return ETeamAttitude::Neutral;
	}

	//Check if actor implements GenericTeamAgentInterface
	auto PlayerTI = Cast<IGenericTeamAgentInterface>(&Other);
	class IGenericTeamAgentInterface* BotTI = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController());
	if (BotTI == nullptr && PlayerTI == nullptr) {
		return ETeamAttitude::Neutral;
	}

	//Get Actor's TeamID
	FGenericTeamId OtherActorTeamId = NULL;
	if (BotTI != nullptr) {
		OtherActorTeamId = BotTI->GetGenericTeamId();
	}
	else if (PlayerTI != nullptr) {
		OtherActorTeamId = PlayerTI->GetGenericTeamId();
	}

	//Check If Hostile
	FGenericTeamId ThisId = GetGenericTeamId();
	if (OtherActorTeamId == -1) {
		return ETeamAttitude::Neutral;
	}
	else if (OtherActorTeamId == ThisId) {
		return ETeamAttitude::Friendly;
	}
	else {
		return ETeamAttitude::Hostile;
	}
}

