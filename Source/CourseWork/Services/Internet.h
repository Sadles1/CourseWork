// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Internet.generated.h"

class UEmailService;
class UMessengerService;

UCLASS()
class COURSEWORK_API UInternet : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UInternet();

	UFUNCTION(BlueprintCallable)
	UMessengerService* GetMessengerService() const {return MessengerService;}
	UFUNCTION(BlueprintCallable)
	UEmailService* GetEmailService() const {return EmailService;}
private:
	
	UPROPERTY(VisibleInstanceOnly, Instanced)
	UEmailService* EmailService = nullptr;
	UPROPERTY(VisibleInstanceOnly, Instanced)
	UMessengerService* MessengerService = nullptr;
};
