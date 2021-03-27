// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CourseWork/WorkPlace/Computer/FileSystem/Files/BaseFile.h"
#include "UObject/Object.h"
#include "BaseEmail.generated.h"

UENUM(BlueprintType)
enum EMailCategory
{
	MC_Sent UMETA(DisplayName = "Sent"),
	MC_Received UMETA(DisplayName = "Received"),
	MC_Deleted UMETA(DisplayName = "Deleted"),

	MC_MAX
};

USTRUCT(BlueprintType)
struct FMail
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString Sender;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString Receiver;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
 	TEnumAsByte<EMailCategory> Category = MC_Sent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString Topic;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString Message;

	UPROPERTY(VisibleAnywhere, Instanced, BlueprintReadWrite)
	TArray<UBaseFile*> AttachedFiles = {};
};


UCLASS(BlueprintType)
class COURSEWORK_API UBaseEmail : public UObject
{
	GENERATED_BODY()

public:

	void SetEmail(const FString NewEmail) {Email = NewEmail;} 
	void SetPassword(const FString NewPassword) {Password = NewPassword;}
	
	void AddMail(const FMail& Mail) {Mails.Add(Mail);}

	FString GetEmail() const {return Email;}
	FString GetPassword() const {return Password;}
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Email;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Password;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FMail> Mails;
};
