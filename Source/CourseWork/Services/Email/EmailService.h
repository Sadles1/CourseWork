// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEmail.h"
#include "GameFramework/Actor.h"
#include "EmailService.generated.h"

class UBasePerson;

UCLASS()
class COURSEWORK_API AEmailService : public AActor
{
	GENERATED_BODY()

public:
	AEmailService();
	void AddNewEmail(UBasePerson* MailOwner, FString Mail, FString Password);

	
	UFUNCTION(BlueprintCallable)
	void SendMail(FMail Mail);

	
	UFUNCTION(BlueprintCallable)
	UBaseEmail* LoginToEmail(const FString Email, const FString Password);

	
protected:
	virtual void BeginPlay() override;

private:
	UBaseEmail* FindEmail(const FString Mail);
    UBaseEmail* FindEmailByOwner(const UBasePerson* Person);

	
	UPROPERTY(VisibleAnywhere, Instanced)
	TArray<UBaseEmail*> AllEmails = {};
};
