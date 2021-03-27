// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseEmail.generated.h"


USTRUCT(BlueprintType)
struct FMail
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Sender;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Receiver;
};


UCLASS()
class COURSEWORK_API UBaseEmail : public UObject
{
	GENERATED_BODY()

public:

	void SetMail(const FString NewMail) {Mail = NewMail;} 
	void SetPassword(const FString NewPassword) {Password = NewPassword;}

	FString GetName() const {return Mail;}
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Mail = "";
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Password = "";

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSet<FMail> SentMails;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSet<FMail> ReceivedMails;
};
