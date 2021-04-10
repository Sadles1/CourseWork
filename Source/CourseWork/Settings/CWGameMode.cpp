// Fill out your copyright notice in the Description page of Project Settings.


#include "CWGameMode.h"
#include "CourseWork/Services/Internet.h"

AInternet* ACWGameMode::GetInternet()
{
	if(!Internet)
		Internet = GetWorld()->SpawnActor<AInternet>();
	
	return Internet;
}