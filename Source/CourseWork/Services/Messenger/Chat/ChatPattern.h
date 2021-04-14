// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ChatPattern.generated.h"


class UMessengerChat;
class UMessengerAccount;
UCLASS(Abstract, BlueprintType, Blueprintable)
class COURSEWORK_API UChatPattern : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	UMessengerChat* CreateChat(UMessengerAccount* User1, UMessengerAccount* User2);
};
