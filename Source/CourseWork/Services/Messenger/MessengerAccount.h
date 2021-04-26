// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Chat/MessengerChat.h"
#include "CourseWork/Services/Base/BaseServiceAccount.h"
#include "CourseWork/WorkPlace/Persons/PersonInfo.h"
#include "Kismet/KismetArrayLibrary.h"


#include "MessengerAccount.generated.h"

struct FMessage;

class UMessengerChat;

UCLASS()
class COURSEWORK_API UMessengerAccount : public UBaseServiceAccount
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	TArray<UMessengerChat*> GetChats() const {return Chats;}

	void AddToChat(UMessengerChat* Chat)
	{
		Chat->AddParticipant(this);
		Chats.Add(Chat);
	}
	
	void SendMsg(UMessengerChat* ToChat, FMessage Msg);

	void SetMail(const FName NewMail) {Mail = NewMail;}

	FName GetMail() const {return Mail;}

	UFUNCTION(BlueprintCallable)
	void SetSecretQuestionCategory(const TEnumAsByte<ESecretQuestion> SecretQuestion);

	UFUNCTION(BlueprintCallable)
	void SetAvailableRecoveryByMail(const bool Available) {bCanRecoveryByMail = Available;}

protected:
	UPROPERTY(VisibleInstanceOnly, Instanced, Category = "Messages")
	TArray<UMessengerChat*> Chats;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Login")
	FName Mail = "";
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Login")
	TEnumAsByte<ESecretQuestion> SecretQuestionCategory;

	UPROPERTY(BlueprintReadOnly)
	bool bCanRecoveryBySecret = false;
	UPROPERTY(BlueprintReadOnly)
	bool bCanRecoveryByMail = true;

	
};
