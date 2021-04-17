// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseDialogScript.generated.h"


UCLASS(Abstract, BlueprintType, Blueprintable)
class UBaseDialogScript : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (DisplayName = "ActivateScript"))
	void BP_ActivateScript();

protected:
	UFUNCTION(BlueprintCallable)
	APlayerController* GetPlayerController() const;
};