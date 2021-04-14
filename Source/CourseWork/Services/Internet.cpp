// Fill out your copyright notice in the Description page of Project Settings.


#include "Internet.h"
#include "Email/EmailService.h"
#include "Messenger/MessengerService.h"


// Sets default values
UInternet::UInternet()
{
	EmailService = CreateDefaultSubobject<UEmailService>(TEXT("Email"));
	MessengerService = CreateDefaultSubobject<UMessengerService>(TEXT("Messenger"));
}

