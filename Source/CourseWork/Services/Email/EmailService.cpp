// Fill out your copyright notice in the Description page of Project Settings.


#include "EmailService.h"
#include "CourseWork/WorkPlace/Persons/Person.h"


AEmailService::AEmailService()
{
	
}


void AEmailService::BeginPlay()
{
	Super::BeginPlay();
}


UBaseEmail* AEmailService::FindEmail(const FString Mail)
{
	for(auto Email : AllEmails)
		if(Email->GetEmail() == Mail)
			return Email;
	return nullptr;
}
UBaseEmail* AEmailService::FindEmailByOwner(const UBasePerson* Person)
{
	for(auto Email : AllEmails)
		if(Email->GetOuter() == Person)
			return Email;
	return nullptr; 
}

void AEmailService::AddNewEmail(UBasePerson* MailOwner, const FString Mail, const FString Password)
{
	UBaseEmail* NewEmail = NewObject<UBaseEmail>(MailOwner);
	NewEmail->SetEmail(Mail);
	NewEmail->SetPassword(Password);
	AllEmails.Add(NewEmail);

	FMail HelloMessage;
	
	HelloMessage.Sender = "Tsu@tsu.ru";
	HelloMessage.Receiver = Mail;
	
	HelloMessage.Topic = "Welcome";
	HelloMessage.Message =
		"We are glad to see you on our platform. If you have any questions or problems you can write to this address";
	
	SendMail(HelloMessage);
}

void AEmailService::SendMail(FMail Mail)
{
	if(Mail.Sender == Mail.Receiver) return;
	
	UBaseEmail* Sender = FindEmail(Mail.Sender);
	Mail.Category = MC_Sent;
	if(Sender)
		Sender->AddMail(Mail);
	
	UBaseEmail* Receiver = FindEmail(Mail.Receiver);
	Mail.Category = MC_Received;
	if(Receiver)
		Receiver->AddMail(Mail);
}

UBaseEmail* AEmailService::LoginToEmail(const FString Email, const FString Password)
{
	UBaseEmail* FoundEmail = FindEmail(Email);
	if(FoundEmail)
		if(FoundEmail->GetPassword() == Password)
			return FoundEmail;
	
	return nullptr;
}
