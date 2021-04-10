// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseService.h"

#include "BaseServiceAccount.h"
#include "CourseWork/WorkPlace/Persons/Person.h"


void UBaseService::AddNewAccount(UBasePerson* AccountOwner, const FName Login, const FName Password)
{
	UBaseServiceAccount* NewAccount = NewObject<UBaseServiceAccount>(AccountOwner, AccountClass);
	NewAccount->SetLogin(Login);
	NewAccount->SetPassword(Password);
	AllAccounts.Add(NewAccount);
}

UBaseServiceAccount* UBaseService::LoginToService(const FName Login, const FName Password)
{
	UBaseServiceAccount* FoundAccount = FindAccount(Login);
	if (FoundAccount)
		if (FoundAccount->GetPassword() == Password)
			return FoundAccount;

	return nullptr;
}

UBaseServiceAccount* UBaseService::FindAccount(const FName Login)
{
	for (auto Account : AllAccounts)
		if (Account->GetLogin() == Login)
			return Account;
	return nullptr;
}

UBaseServiceAccount* UBaseService::FindAccountByOwner(const UBasePerson* OwnerPerson)
{
	for (auto Account : AllAccounts)
		if (Account->GetOuter() == OwnerPerson)
			return Account;
	return nullptr;
}