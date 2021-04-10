// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseServiceAccount.generated.h"


UCLASS(Abstract)
class COURSEWORK_API UBaseServiceAccount : public UObject
{
	GENERATED_BODY()

public:
	void SetLogin(const FName NewLogin) {Login = NewLogin;} 
	void SetPassword(const FName NewPassword) {Password = NewPassword;}
	
	FName GetLogin() const {return Login;}
	FName GetPassword() const {return Password;}
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    FName Login;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    FName Password;
};
