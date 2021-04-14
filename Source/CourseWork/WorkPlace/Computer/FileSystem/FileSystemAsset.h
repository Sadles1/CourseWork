// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FileSystemAsset.generated.h"

class UBaseFileCatalogue;

UCLASS(Abstract, Blueprintable)
class COURSEWORK_API UFileSystemAsset : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	UBaseFileCatalogue* GenerateFileSystem();
};
