﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MessengerService.h"
#include "MessengerAccount.h"
#include "Chat/MessengerChat.h"
#include "Chat/Message.h"
#include "Chat/ChatPattern.h"
#include "CourseWork/WorkPlace/Persons/Person.h"
#include "Kismet/KismetMathLibrary.h"


const TArray<TEnumAsByte<ESecretQuestion>> UMessengerService::SecretQuestionCategory = {
	SQ_BirthPlace, SQ_ChildhoodFriend, SQ_FavoriteFilm, SQ_FavoriteFood,
};

// Sets default values
UMessengerService::UMessengerService()
{
	AccountClass = UMessengerAccount::StaticClass();

	Support = CreateDefaultSubobject<UMessengerAccount>(TEXT("Support"));
	Support->SetLogin("Support");
}

void UMessengerService::AddNewAccount(UBasePerson* AccountOwner, const FName& Login, const FName& Password)
{
	Super::AddNewAccount(AccountOwner, Login, Password);

	UMessengerAccount* SelfAccount = Cast<UMessengerAccount>(FindAccountByOwner(AccountOwner));
	if(SelfAccount)
	{
		const TEnumAsByte<ESecretQuestion> SecretQuestion = SecretQuestionCategory[UKismetMathLibrary::RandomInteger(
			SecretQuestionCategory.Num())];


		
		FMessage Msg;
		Msg.Sender = Support;
	
		Msg.Message = FText::FromString(
            "We are glad to see you on our platform. If you have any questions or problems you can write to this chat");

	
		UMessengerChat* SupportChat = NewObject<UMessengerChat>(Support);
		SupportChat->SetChatName("Support");
		
		Support->AddToChat(SupportChat);
		SelfAccount->AddToChat(SupportChat);
		
		SelfAccount->SendMsg(SupportChat, Msg);
	}
}

void UMessengerService::CreateNewChatByPattern(const TSubclassOf<UChatPattern> Pattern, UMessengerAccount* User1, UMessengerAccount* User2)
{
	UChatPattern* ChatPattern = NewObject<UChatPattern>(this, Pattern);
	if(ChatPattern)
	{
		UMessengerChat* NewChat = ChatPattern->CreateChat(User1, User2);
		
		User1->AddToChat(NewChat);
		User2->AddToChat(NewChat);
	}
}

UMessengerAccount* UMessengerService::FindAccountByMail(const FName& Mail)
{
	for(auto Account : AllAccounts)
	{
		UMessengerAccount* MsgAccount = Cast<UMessengerAccount>(Account);
		if(Mail == MsgAccount->GetMail())
		{
			return MsgAccount;
		}
	}
	return nullptr;
}
