// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MessengerService.generated.h"

class UBasePerson;
UCLASS()
class COURSEWORK_API AMessengerService : public AActor
{
	GENERATED_BODY()

public:
	AMessengerService();

	void AddNewAccount(UBasePerson* MessengerOwner, const FName Mail, const FString Password) ;

protected:
	virtual void BeginPlay() override;
};
