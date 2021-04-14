// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Message.h"
#include "MessengerChat.generated.h"

UCLASS(BlueprintType)
class COURSEWORK_API UMessengerChat : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddMessage(const FMessage Msg) {Messages.Add(Msg);}

	UFUNCTION(BlueprintCallable)
	void SetChatName(const FName NewChatName) {ChatName = NewChatName;}
	
protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	FName ChatName = "Chat";
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<FMessage> Messages = {};
};
