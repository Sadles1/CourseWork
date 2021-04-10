// Fill out your copyright notice in the Description page of Project Settings.


#include "Person.h"
#include "CourseWork/Services/Internet.h"
#include "CourseWork/Services/Email/EmailService.h"
#include "CourseWork/Settings/CWGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


const TArray<FString> UBasePerson::AllNames = {
	"Vitaliy", "Alexey", "Pavel", "Dmitry", "John", "James", "Evgeniy", "Sergei", "Ivan", "Nikolay", "Michael",
	"Pupa", "Lupa", "Biba", "Boba"
};

const TArray<FString> UBasePerson::AllMiddleNames = {
	"Vitalievich", "Alexeyevich", "Dmitrievich", "Nikolayevich", "Petrovich"
};

const TArray<FString> UBasePerson::AllLastNames = {
	"Zubenko", "Ivanov", "Petrov", "Smirnov", "Kuznetsov", "Popov", "Vasiliev", "Sokolov", "Novikov", "Fedorov",
	"Morozov", "Volkow", "Alekseyev", "Lebedev", "Semenov", "Yegorov", "Pavlov", "Kozlov", "Stepanov",  "Nikolaev",
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
	ComputerLoginData.Password = "12345";
	ComputerLoginData.bRememberLogin = true;
	
	const TTuple<TEnumAsByte<EApp>, FLoginData> ComputerPass(App_Computer, ComputerLoginData);
	LoginsData.Add(ComputerPass);

	UEmailService* EmailService = Cast<ACWGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->GetInternet()->
		GetEmailService();
	
	if(EmailService)
	{
		FLoginData MailLoginData;
		MailLoginData.Login = *(LastName.ToString() + FString::FromInt(BirthDate.GetYear()) + "@tsu.ru");
		MailLoginData.Password = "12345";
		MailLoginData.bRememberLogin = true;
		
		const TTuple<TEnumAsByte<EApp>, FLoginData> MailPass(App_Mail, MailLoginData);
		LoginsData.Add(MailPass);
		
		EmailService->AddNewAccount(this, MailLoginData.Login, MailLoginData.Password);
	}
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
