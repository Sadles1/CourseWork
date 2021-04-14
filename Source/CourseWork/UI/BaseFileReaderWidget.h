// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseApplicationWidget.h"
#include "BaseFileReaderWidget.generated.h"

class UBaseFile;


UCLASS(Abstract)
class COURSEWORK_API UBaseFileReaderWidget : public UBaseApplicationWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReadFile();
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true", AllowPrivateAccess = "true"))
	UBaseFile* FileToRead;

	UFUNCTION(BlueprintCallable)
	void AddFile(UBaseFile* File);


};
