// Fill out your copyright notice in the Description page of Project Settings.


#include "MessengerService.h"
#include "MessengerAccount.h"


// Sets default values
UMessengerService::UMessengerService()
{
	AccountClass = UMessengerAccount::StaticClass();
}