// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CourseWork/Services/Base/BaseServiceAccount.h"
#include "MessengerAccount.generated.h"


UCLASS()
class COURSEWORK_API UMessengerAccount : public UBaseServiceAccount
{
	GENERATED_BODY()

	
public:
	

protected:
	
	TMap<UMessengerAccount*, TArray<FText>> Messages;
};
