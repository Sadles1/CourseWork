// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Message.generated.h"

class UMessengerAccount;

USTRUCT(BlueprintType)
struct FMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	UMessengerAccount* Sender = nullptr;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	FText Message;

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	bool bRead = true;
	
};