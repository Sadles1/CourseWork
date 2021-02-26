// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "BaseFile.generated.h"

class UBaseFileReaderWidget;


UCLASS(Abstract, BlueprintType, Blueprintable)
class COURSEWORK_API UBaseFile : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FileInfo", meta = (ExposeOnSpawn="true", AllowPrivateAccess = "true"))
	FName FileName = "Doc";

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FileInfo", meta = (AllowPrivateAccess = "true"))
	UObject* Image;

	UPROPERTY(EditDefaultsOnly, Category = "FileInfo")
	FName FileExtension;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UBaseFileReaderWidget> FileReaderWidgetClass;

};
