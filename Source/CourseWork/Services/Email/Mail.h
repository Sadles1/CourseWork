// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mail.generated.h"

class UBaseFile;

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
	FName Sender;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FName Receiver;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TEnumAsByte<EMailCategory> Category = MC_Sent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText Topic;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText Message;

	UPROPERTY(VisibleAnywhere, Instanced, BlueprintReadWrite)
	TArray<UBaseFile*> AttachedFiles = {};
};