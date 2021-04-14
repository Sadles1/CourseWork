// Fill out your copyright notice in the Description page of Project Settings.


#include "EmailService.h"
#include "Mail.h"
#include "CourseWork/WorkPlace/Persons/Person.h"


UEmailService::UEmailService()
{
	AccountClass = UEmailAccount::StaticClass();
}
void UEmailService::SendMail(FMail Mail)
{
	if (Mail.Sender == Mail.Receiver) return;

	UEmailAccount* Sender = Cast<UEmailAccount>(FindAccount(Mail.Sender));
	Mail.Category = MC_Sent;
	if (Sender)
		Sender->ReceiveMail(Mail);

	UEmailAccount* Receiver = Cast<UEmailAccount>(FindAccount(Mail.Receiver));
	
	Mail.Category = MC_Received;
	if (Receiver)
		Receiver->ReceiveMail(Mail);
}

void UEmailService::AddNewAccount(UBasePerson* AccountOwner, const FName& Login, const FName& Password)
{
	Super::AddNewAccount(AccountOwner, Login, Password);

	FMail HelloMessage;

	HelloMessage.Sender = "Tsu@tsu.ru";
	HelloMessage.Receiver = Login;

	HelloMessage.Topic = FText::FromString("Welcome");
	HelloMessage.Message = FText::FromString(
		"We are glad to see you on our platform. If you have any questions or problems you can write to this address");

	SendMail(HelloMessage);
}
