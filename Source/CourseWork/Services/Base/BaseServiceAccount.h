// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseServiceAccount.generated.h"


UCLASS(Abstract, BlueprintType, Blueprintable)
class COURSEWORK_API UBaseServiceAccount : public UObject
{
	GENERATED_BODY()

public:

	//Setters
	UFUNCTION(BlueprintCallable)
	void SetLogin(const FName& NewLogin) {Login = NewLogin;}
	UFUNCTION(BlueprintCallable)
	void SetPassword(const FName& NewPassword) {Password = NewPassword;}

	//Getters
	FName GetLogin() const {return Login;}
	FName GetPassword() const {return Password;}
	
protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Login")
    FName Login;
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Login")
    FName Password;
};
