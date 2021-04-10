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
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	UMessengerAccount* Sender = nullptr;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	FText Message;

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	bool bRead = false;
	
};