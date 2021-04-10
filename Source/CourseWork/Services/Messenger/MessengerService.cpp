// Fill out your copyright notice in the Description page of Project Settings.


#include "MessengerService.h"
#include "MessengerAccount.h"


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
		
		SelfAccount->AddToChat(SupportChat);
		SelfAccount->ReceiveMsg(SupportChat, Msg);
	}
}
