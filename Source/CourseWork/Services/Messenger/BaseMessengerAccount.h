// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseMessengerAccount.generated.h"


UCLASS()
class COURSEWORK_API UBaseMessengerAccount : public UObject
{
	GENERATED_BODY()

	
public:
	

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName Login;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Password;


	TMap<FName, TArray<FText>> Messages;
};
