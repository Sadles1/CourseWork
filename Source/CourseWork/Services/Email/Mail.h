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
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	FName Sender;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	FName Receiver;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	TEnumAsByte<EMailCategory> Category = MC_Received;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	FText Topic;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	FText Message;

	UPROPERTY(VisibleInstanceOnly, Instanced, BlueprintReadWrite)
	TArray<UBaseFile*> AttachedFiles = {};
};