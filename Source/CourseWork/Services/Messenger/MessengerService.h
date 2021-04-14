// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CourseWork/Services/Base/BaseService.h"
#include "CourseWork/WorkPlace/Persons/PersonInfo.h"
#include "MessengerService.generated.h"

class UMessengerAccount;
class UChatPattern;
class UBasePerson;

UCLASS()
class COURSEWORK_API UMessengerService : public UBaseService
{
	GENERATED_BODY()

public:
	UMessengerService();

	virtual void AddNewAccount(UBasePerson* AccountOwner, const FName& Login, const FName& Password) override;

	UPROPERTY()
	UMessengerAccount* Support = nullptr;

	UFUNCTION(BlueprintCallable)
	void CreateNewChatByPattern(const TSubclassOf<UChatPattern> Pattern, UMessengerAccount* User1,
	                            UMessengerAccount* User2);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UMessengerAccount* FindAccountByMail(const FName& Mail);

	const static TArray<TEnumAsByte<ESecretQuestion>> SecretQuestionCategory; 
	                                                    
};
