// Made by Steven Kearney

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "BaseCharacter.generated.h"

UCLASS()
class LDP_API ABaseCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FGenericTeamId TeamId;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Team", meta = (ToolTip = "The team the unit belongs to.\n'-1' = Neutral (No team). This won't agro other teams nor will it try to attack other teams. Consider setting NPCs to this.\n'0' = Default Enemy Team. Any newly created enemy will default to this team.\n'1' = Player's Team. Creating a new player from the base player character will default you to this team. If you want to create new summons, make sure to add it to this team.\nA matching ID is an ally, and everyother value is hostile. You can set other values to represent different enemy factions that will attack each other."))
	int32 TeamID = 0;

	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }

};
