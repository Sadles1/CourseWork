// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EmailAccount.h"
#include "CourseWork/Services/Base/BaseService.h"
#include "EmailService.generated.h"

class UBasePerson;

UCLASS()
class COURSEWORK_API UEmailService : public UBaseService
{
	GENERATED_BODY()

public:
	UEmailService();
	
	UFUNCTION(BlueprintCallable)
	void SendMail(FMail Mail);

	virtual void AddNewAccount(UBasePerson* AccountOwner, const FName Login, const FName Password) override;

private:	
	UPROPERTY(VisibleAnywhere, Instanced)
	TArray<UEmailAccount*> AllEmails = {};
};
