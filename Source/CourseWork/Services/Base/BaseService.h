// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "BaseServiceAccount.h"
#include "UObject/Object.h"
#include "BaseService.generated.h"

class UEmailAccount;
class UBasePerson;
class UBaseServiceAccount;


UCLASS(Abstract)
class COURSEWORK_API UBaseService : public UObject
{
	GENERATED_BODY()

public:

	virtual void AddNewAccount(UBasePerson* AccountOwner, const FName Login, const FName Password);

	UFUNCTION(BlueprintCallable)
	UBaseServiceAccount* LoginToService(const FName Login, const FName Password);

	UBaseServiceAccount* FindAccount(const FName Login);
	UBaseServiceAccount* FindAccountByOwner(const UBasePerson* OwnerPerson);
	
protected:
	

	UPROPERTY()
	TSubclassOf<UBaseServiceAccount> AccountClass = nullptr;

	
	UPROPERTY(VisibleInstanceOnly, Instanced)
	TArray<UBaseServiceAccount*> AllAccounts = {};
};