// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CWGameMode.generated.h"


class AInternet;
UCLASS()
class COURSEWORK_API ACWGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AInternet* GetInternet();
	
private:
	UPROPERTY()
	AInternet* Internet = nullptr;
};
