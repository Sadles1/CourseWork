// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDialogScript.h"

APlayerController* UBaseDialogScript::GetPlayerController() const
{
	return GetWorld()->GetFirstPlayerController();
}
