// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CourseWork/Services/Base/BaseServiceAccount.h"
#include "Mail.h"
#include "EmailAccount.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReceiveMailDelegate);

UCLASS()
class COURSEWORK_API UEmailAccount : public UBaseServiceAccount
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FReceiveMailDelegate ReceiveMailDelegate;
	
	void ReceiveMail(const FMail& Mail)
	{
		Mails.Add(Mail);
		ReceiveMailDelegate.Broadcast();
	}

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FMail> Mails;
};
