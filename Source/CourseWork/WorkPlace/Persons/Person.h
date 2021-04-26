// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PersonInfo.h"

#include "Person.generated.h"

class UBaseServiceAccount;
class UDataTable;

USTRUCT(BlueprintType)
struct FLoginData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	FName Login = "";
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	FName Password = "";

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	UBaseServiceAccount* Account = nullptr;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	bool bRememberLogin = false;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	bool bRememberPassword = false;
};

UENUM(BlueprintType)
enum EApp
{
	App_Computer UMETA(DisplayName = "Computer"),
	App_Mail UMETA(DisplayName = "Mail"),
	App_Messenger UMETA(DisplayName = "Messenger"),

	App_MAX,
};

UENUM(BlueprintType)
enum EPosition
{
	P_Worker UMETA(DisplayName = "Worker"),
	P_Manager UMETA(DisplayName = "Manager"),
	P_Secretary UMETA(DisplayName = "Secretary"),
	P_Director UMETA(DisplayName = "Director"),
	P_Security UMETA(DisplayName = "Security"),
	P_SystemAdministrator UMETA(DisplayName = "SystemAdministrator"),

	P_MAX,
};

UENUM(BlueprintType)
enum EPasswordDifficulty
{
	PD_Easy UMETA(DisplayName = "Easy"),
	PD_Medium UMETA(DisplayName = "Medium"),
	PD_Hard UMETA(DisplayName = "Hard"),

	PD_MAX,
};

UCLASS(Blueprintable)
class COURSEWORK_API UBasePerson : public UObject
{
	GENERATED_BODY()
	
public:
	void InitPerson(TEnumAsByte<EPosition> Post);

	UFUNCTION(BlueprintCallable)
	void GenerateSelfInfo(const TEnumAsByte<ESecretQuestion> InfoCategory);

	UFUNCTION(BlueprintCallable)
	FLoginData GetLoginData(TEnumAsByte<EApp> LoginDataType) const;

	UFUNCTION(BlueprintCallable)
    void SetLoginData(FLoginData LoginData, TEnumAsByte<EApp> LoginDataType);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetPersonalInfo(const TEnumAsByte<ESecretQuestion> InfoCategory)
	{
		return *SelfInfo.Find(InfoCategory);
	}
	
protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FText FirstName = FText::FromString("");
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FText MiddleName = FText::FromString("");
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FText LastName = FText::FromString("");
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EPosition> Position = P_Worker;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDateTime BirthDate = {};

	
private:

	UPROPERTY(VisibleInstanceOnly)
	TMap<TEnumAsByte<EApp>, FLoginData> LoginsData = {};

	UPROPERTY(VisibleInstanceOnly)
	TMap<TEnumAsByte<ESecretQuestion>, FText> SelfInfo = {};
	
	static FDateTime GetRandomBirthDate(TEnumAsByte<EPosition> Post);
	static const TMap<TEnumAsByte<EPosition>, TTuple<int16, int16>> YearOfBirth;
	
	static FText GetRandomName();
	static const TArray<FString> AllNames; 
	
	static FText GetRandomMiddleName();
	static const TArray<FString> AllMiddleNames; 
	
	FText GetRandomLastName() const;

	FName GetRepeatedPassword(TEnumAsByte<EApp> PassToRepeat); 

	UFUNCTION(BlueprintCallable)
	FName GenerateRandomPassword(TEnumAsByte<EPasswordDifficulty> Difficulty);

	UPROPERTY(EditDefaultsOnly)
	UDataTable* EasyPasswordsDataTable = nullptr;

	UPROPERTY(EditDefaultsOnly)
	UDataTable* FilmsDataTable = nullptr;

	UPROPERTY(EditDefaultsOnly)
	UDataTable* SurnamesDataTable = nullptr;
	
	static FName GenerateHardPassword();

	UFUNCTION(BlueprintCallable)
	void SetPersonPassword(const TEnumAsByte<EApp> App, const TEnumAsByte<EPasswordDifficulty> PassDifficulty);
	UFUNCTION(BlueprintCallable)
	void SetRepeatedPassword(TEnumAsByte<EApp> App, TEnumAsByte<EApp> PassToRepeat);
};