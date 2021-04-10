// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Internet.generated.h"

class UEmailService;
class UMessengerService;

UCLASS()
class COURSEWORK_API AInternet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInternet();

	UFUNCTION(BlueprintCallable)
	UMessengerService* GetMessengerService() const {return MessengerService;}
	UFUNCTION(BlueprintCallable)
	UEmailService* GetEmailService() const {return EmailService;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	UPROPERTY(VisibleInstanceOnly, Instanced)
	UEmailService* EmailService = nullptr;
	UPROPERTY(VisibleInstanceOnly, Instanced)
	UMessengerService* MessengerService = nullptr;
};
