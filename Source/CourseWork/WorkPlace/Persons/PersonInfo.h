﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PersonInfo.generated.h"

UENUM()
enum ESecretQuestion
{
	SQ_FavoriteFood UMETA(DisplayName = "FavoriteFood"),
	SQ_FavoriteFilm UMETA(DisplayName = "FavoriteFilm"),
	SQ_ChildhoodFriend UMETA(DisplayName = "ChildhoodFriend"),
	SQ_BirthPlace UMETA(DisplayName = "BirthPlace"),

	SQ_MAX,
};


USTRUCT(BlueprintType)
struct FPasswords : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> PasswordVariants;
};

USTRUCT(BlueprintType)
struct FSurnames : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Surnames;
};

USTRUCT(BlueprintType)
struct FFilms : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> Films;
};