// Fill out your copyright notice in the Description page of Project Settings.


#include "CWGameMode.h"
#include "CourseWork/Services/Internet.h"

UInternet* ACWGameMode::GetInternet()
{
	if(!Internet)
		Internet = NewObject<UInternet>();
	
	return Internet;
}