// Fill out your copyright notice in the Description page of Project Settings.


#include "CWGameMode.h"

#include "Kismet/GameplayStatics.h"

AEmailService* ACWGameMode::GetEmailService()
{
	if(EmailService)
		return EmailService;
	
	EmailService = Cast<AEmailService>(UGameplayStatics::GetActorOfClass(GetWorld(), AEmailService::StaticClass()));
	return EmailService;
}
