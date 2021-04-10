// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CourseWork/Services/Base/BaseServiceAccount.h"
#include "Mail.h"
#include "EmailAccount.generated.h"


UCLASS(BlueprintType)
class COURSEWORK_API UEmailAccount : public UBaseServiceAccount
{
	GENERATED_BODY()

public:
	void ReceiveMail(const FMail& Mail) {Mails.Add(Mail);}
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FMail> Mails;
};