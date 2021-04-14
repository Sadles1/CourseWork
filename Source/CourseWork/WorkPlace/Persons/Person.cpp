﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "Person.h"


#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/DataTable.h"


#include "CourseWork/Services/Internet.h"
#include "CourseWork/Settings/CWGameMode.h"
#include "CourseWork/Services/Email/EmailService.h"
#include "CourseWork/Services/Messenger/MessengerService.h"
#include "CourseWork/Services/Messenger/MessengerAccount.h"


const TArray<FString> UBasePerson::AllNames = {
	"Vitaliy", "Alexey", "Pavel", "Dmitry", "John", "James", "Evgeniy", "Sergei", "Ivan", "Nikolay", "Michael",
	"Pupa", "Lupa", "Biba", "Boba"
};
const TArray<FString> UBasePerson::AllMiddleNames = {
	"Vitalievich", "Alexeyevich", "Dmitrievich", "Nikolayevich", "Petrovich"
};
const TArray<FString> UBasePerson::AllLastNames = {
	"Zubenko", "Ivanov", "Petrov", "Smirnov", "Kuznetsov", "Popov", "Vasiliev", "Sokolov", "Novikov", "Fedorov",
	"Morozov", "Volkow", "Alekseyev", "Lebedev", "Semenov", "Yegorov", "Pavlov", "Kozlov", "Stepanov", "Nikolaev",
	"Orlov", "Andreev",
};

const TMap<TEnumAsByte<EPosition>, TTuple<int16, int16>> UBasePerson::YearOfBirth = {
	{P_Worker, TTuple<int16, int16>(1975, 2003)},
	{P_Manager, TTuple<int16, int16>(1970, 1990)},
	{P_Secretary, TTuple<int16, int16>(1980, 1990)},
	{P_Director, TTuple<int16, int16>(1950, 1980)},
	{P_Security, TTuple<int16, int16>(1975, 2003)},
	{P_SystemAdministrator, TTuple<int16, int16>(1985, 1995)}
};

FLoginData UBasePerson::GetLoginData(const TEnumAsByte<EApp> LoginDataType) const
{
	return LoginsData.FindRef(LoginDataType);
}

void UBasePerson::SetLoginData(FLoginData LoginData, TEnumAsByte<EApp> LoginDataType)
{
	LoginsData.Emplace(LoginDataType, LoginData);
}

void UBasePerson::InitPerson(const TEnumAsByte<EPosition> Post)
{
	//EasyPasswords =;
	EasyPasswords = *EasyPasswordsDataTable->FindRow<FPasswords>("EasyPasswords", "");

	Position = Post;

	if (Position == P_Director)
	{
		FirstName = FText::FromString("Michael");
		MiddleName = FText::FromString("Petrovich");
		LastName = FText::FromString("Zubenko");
	}
	else
	{
		FirstName = GetRandomName();
		MiddleName = GetRandomMiddleName();
		LastName = GetRandomLastName();
	}

	BirthDate = GetRandomBirthDate(Post);

	FLoginData ComputerLoginData;
	ComputerLoginData.Login = *FirstName.ToString();
	ComputerLoginData.Password = GenerateRandomPassword(PD_Easy);
	ComputerLoginData.bRememberLogin = true;

	const TTuple<TEnumAsByte<EApp>, FLoginData> ComputerPass(App_Computer, ComputerLoginData);
	LoginsData.Add(ComputerPass);

	FName Login = *(LastName.ToString() + FString::FromInt(BirthDate.GetYear()));

	UEmailService* EmailService = Cast<ACWGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->GetInternet()->
		GetEmailService();

	if (EmailService)
	{
		FLoginData MailLoginData;
		MailLoginData.Login = *(Login.ToString() + "@tsu.ru");
		MailLoginData.Password = "12345";
		MailLoginData.bRememberLogin = true;

		const TTuple<TEnumAsByte<EApp>, FLoginData> Pass(App_Mail, MailLoginData);
		LoginsData.Add(Pass);

		EmailService->AddNewAccount(this, MailLoginData.Login, MailLoginData.Password);
	}

	UMessengerService* MessengerService = Cast<ACWGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->GetInternet()->
		GetMessengerService();

	if (MessengerService)
	{
		FLoginData MessengerLoginData;
		MessengerLoginData.Login = Login;
		MessengerLoginData.Password = "12345";
		MessengerLoginData.bRememberLogin = true;

		const TTuple<TEnumAsByte<EApp>, FLoginData> Pass(App_Messenger, MessengerLoginData);
		LoginsData.Add(Pass);

		MessengerService->AddNewAccount(this, MessengerLoginData.Login, MessengerLoginData.Password);

		UMessengerAccount* Account = Cast<UMessengerAccount>(MessengerService->FindAccountByOwner(this));

		Account->SetMail(GetLoginData(App_Mail).Login);
	}
}

void UBasePerson::GenerateSelfInfo(const TEnumAsByte<ESecretQuestion> InfoCategory)
{
	TTuple<TEnumAsByte<ESecretQuestion>, FText> TupleInfo;
	TupleInfo.Key = InfoCategory;
	switch (InfoCategory)
	{
	case SQ_FavoriteFood:
		{
			TupleInfo.Value = FText::FromString("Fish");
			break;
		}
	case SQ_FavoriteFilm:
		{
			TupleInfo.Value = FText::FromString("Avangers");
			break;
		}
	case SQ_FavoriteSeries:
		{
			TupleInfo.Value = FText::FromString("Game of thrones");
			break;
		}
	case SQ_FavoriteMusic:
		{
			TupleInfo.Value = FText::FromString("Coi");
			break;
		}
	case SQ_ChildhoodFriend:
		{
			TupleInfo.Value = GetRandomName();
			break;
		}
	case SQ_SecondSurname:
		{
			TupleInfo.Value = GetRandomLastName();
			break;
		}
	case SQ_BirthPlace:
		{
			TupleInfo.Value = FText::FromString("Perm");
			break;
		}
	default:
		{
			break;
		}
	}

	SelfInfo.Add(TupleInfo);
}

FDateTime UBasePerson::GetRandomBirthDate(const TEnumAsByte<EPosition> Post)
{
	const int16 Year = UKismetMathLibrary::RandomIntegerInRange(YearOfBirth.Find(Post)->Key,
	                                                            YearOfBirth.Find(Post)->Value);
	const int8 Month = UKismetMathLibrary::RandomIntegerInRange(1, 12);
	const int8 Day = UKismetMathLibrary::RandomIntegerInRange(1, FDateTime::DaysInMonth(Year, Month));

	const FDateTime BirthDate(Year, Month, Day);
	return BirthDate;
}

FText UBasePerson::GetRandomName()
{
	return FText::FromString(AllNames[UKismetMathLibrary::RandomInteger(AllNames.Num())]);
}

FText UBasePerson::GetRandomMiddleName()
{
	return FText::FromString(AllMiddleNames[UKismetMathLibrary::RandomInteger(AllMiddleNames.Num())]);
}

FText UBasePerson::GetRandomLastName()
{
	return FText::FromString(AllLastNames[UKismetMathLibrary::RandomInteger(AllLastNames.Num())]);
}

FName UBasePerson::GenerateRandomPassword(const TEnumAsByte<EPasswordDifficulty> Difficulty)
{
	FName Password = "";
	switch (Difficulty)
	{
	case PD_Easy:
		{
			Password = EasyPasswords.PasswordVariants[UKismetMathLibrary::RandomInteger(
				EasyPasswords.PasswordVariants.Num())];
			break;
		}
	case PD_Medium:
		{
			break;
		}
	case PD_Hard:
		{
			break;
		}
	case PD_Repeated:
		{
			Password = LoginsData.Find(App_Computer)->Password;
			break;
		}
	default:
		{
			break;
		}
	}
	return Password;
}