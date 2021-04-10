// Fill out your copyright notice in the Description page of Project Settings.


#include "Internet.h"

#include "Email/EmailAccount.h"
#include "Email/EmailService.h"
#include "Messenger/MessengerService.h"


// Sets default values
AInternet::AInternet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	EmailService = CreateDefaultSubobject<UEmailService>(TEXT("Email"));
	MessengerService = CreateDefaultSubobject<UMessengerService>(TEXT("Messenger"));
}

// Called when the game starts or when spawned
void AInternet::BeginPlay()
{
	Super::BeginPlay();
}


