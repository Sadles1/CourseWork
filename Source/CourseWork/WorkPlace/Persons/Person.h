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
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Login;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Password;
};

UENUM(BlueprintType)
enum ELoginData
{
	LD_Computer UMETA(DisplayName = "Computer"),
	LD_Mail UMETA(DisplayName = "Mail"),
	LD_Messenger UMETA(DisplayName = "Messenger"),

	LD_MAX,
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
	UFUNCTION(BlueprintCallable)
	FLoginData GetLoginData(TEnumAsByte<ELoginData> LoginDataType) const;

	UFUNCTION(BlueprintCallable)
	void InitPerson(TEnumAsByte<EPosition> Post);
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
	TMap<TEnumAsByte<ELoginData>, FLoginData> LoginsData = {};

	
	static FDateTime GetRandomBirthDate(TEnumAsByte<EPosition> Post);
	static const TMap<TEnumAsByte<EPosition>, TTuple<int16, int16>> YearOfBirth;

	
	static FText GetRandomName();
	static const TArray<FString> AllNames; 
	
	static FText GetRandomMiddleName();
	static const TArray<FString> AllMiddleNames; 
	
	static FText GetRandomLastName();
	static const TArray<FString> AllLastNames; 
	
};
