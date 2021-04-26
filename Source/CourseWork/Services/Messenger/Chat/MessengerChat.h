// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Message.h"
#include "CourseWork/WorkPlace/Persons/Person.h"

#include "MessengerChat.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAddMessageDelegate);

UCLASS(BlueprintType)
class COURSEWORK_API UMessengerChat : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FAddMessageDelegate AddMessageDelegate;

	UFUNCTION(BlueprintCallable)
	void AddParticipant(UMessengerAccount* Participant)
	{
		Participants.Add(Participant);
	}
	
	UFUNCTION(BlueprintCallable)
	void AddMessage(const FMessage Msg)
	{
		Messages.Add(Msg);
		AddMessageDelegate.Broadcast();
	}

	UFUNCTION(BlueprintCallable)
	void SetChatName(const FName NewChatName) {ChatName = NewChatName;}
	
protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	FName ChatName = "Chat";
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<FMessage> Messages = {};

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	TArray<FDialogMessage> DialogMessages = {};

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	TArray<UMessengerAccount*> Participants = {};
};
