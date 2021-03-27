// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CourseWork/Services/Email/EmailService.h"
#include "GameFramework/GameModeBase.h"
#include "CWGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COURSEWORK_API ACWGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AEmailService* GetEmailService();

private:
	UPROPERTY(VisibleAnywhere)
	AEmailService* EmailService = nullptr;
};
