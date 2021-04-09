// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Person.generated.h"

USTRUCT(BlueprintType)
struct FLoginData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString Login = "";
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString Password = "";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bRememberLogin = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
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

UCLASS(Blueprintable)
class COURSEWORK_API UBasePerson : public UObject
{
	GENERATED_BODY()
	
public:
	void InitPerson(TEnumAsByte<EPosition> Post);

	
	UFUNCTION(BlueprintCallable)
	FLoginData GetLoginData(TEnumAsByte<EApp> LoginDataType) const;

	UFUNCTION(BlueprintCallable)
    void SetLoginData(FLoginData LoginData, TEnumAsByte<EApp> LoginDataType) ;
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
	
	UPROPERTY(VisibleAnywhere)
	TMap<TEnumAsByte<EApp>, FLoginData> LoginsData = {};
	
	static FDateTime GetRandomBirthDate(TEnumAsByte<EPosition> Post);
	static const TMap<TEnumAsByte<EPosition>, TTuple<int16, int16>> YearOfBirth;

	
	static FText GetRandomName();
	static const TArray<FString> AllNames; 
	
	static FText GetRandomMiddleName();
	static const TArray<FString> AllMiddleNames; 
	
	static FText GetRandomLastName();
	static const TArray<FString> AllLastNames; 
	
};
