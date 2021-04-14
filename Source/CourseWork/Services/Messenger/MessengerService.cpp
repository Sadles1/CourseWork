// Fill out your copyright notice in the Description page of Project Settings.


#include "MessengerService.h"
#include "MessengerAccount.h"
#include "Chat/MessengerChat.h"
#include "Chat/Message.h"
#include "Chat/ChatPattern.h"


// Sets default values
UMessengerService::UMessengerService()
{
	AccountClass = UMessengerAccount::StaticClass();

	Support = CreateDefaultSubobject<UMessengerAccount>(TEXT("Support"));
}

void UMessengerService::AddNewAccount(UBasePerson* AccountOwner, const FName Login, const FName Password)
{
	Super::AddNewAccount(AccountOwner, Login, Password);

	UMessengerAccount* SelfAccount = Cast<UMessengerAccount>(FindAccountByOwner(AccountOwner));
	if(SelfAccount)
	{
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