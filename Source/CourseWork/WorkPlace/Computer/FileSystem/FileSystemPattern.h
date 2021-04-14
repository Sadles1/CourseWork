// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FileSystemPattern.generated.h"

class UBaseFileCatalogue;

UCLASS(Abstract, Blueprintable)
class COURSEWORK_API UFileSystemPattern : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	UBaseFileCatalogue* GenerateFileSystem();
};
