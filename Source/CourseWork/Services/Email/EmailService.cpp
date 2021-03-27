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
		if(Email->GetName() == Mail)
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
	NewEmail->SetMail(Mail);
	NewEmail->SetPassword(Password);
	AllEmails.Add(NewEmail);
}
