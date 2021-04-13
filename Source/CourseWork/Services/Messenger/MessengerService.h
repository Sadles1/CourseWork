﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChatPattern.h"
#include "MessengerAccount.h"
#include "CourseWork/Services/Base/BaseService.h"
#include "MessengerService.generated.h"

class UBasePerson;
UCLASS()
class COURSEWORK_API UMessengerService : public UBaseService
{
	GENERATED_BODY()

public:
	UMessengerService();

	virtual void AddNewAccount(UBasePerson* AccountOwner, const FName Login, const FName Password) override;

	UPROPERTY()
	UMessengerAccount* Support = nullptr;

	UFUNCTION(BlueprintCallable)
	void CreateNewChatByPattern(const TSubclassOf<UChatPattern> Pattern, UMessengerAccount* User1,
	                            UMessengerAccount* User2);
};
