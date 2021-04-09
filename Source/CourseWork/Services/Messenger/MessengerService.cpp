// Fill out your copyright notice in the Description page of Project Settings.


#include "MessengerService.h"

#include "BaseMessengerAccount.h"
#include "CourseWork/WorkPlace/Persons/Person.h"


// Sets default values
AMessengerService::AMessengerService()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AMessengerService::AddNewAccount(UBasePerson* MessengerOwner, const FName Mail, const FString Password)
{
	UBaseMessengerAccount* NewAccount = NewObject<UBaseMessengerAccount>(MessengerOwner);
}

// Called when the game starts or when spawned
void AMessengerService::BeginPlay()
{
	Super::BeginPlay();
}

