// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PersonInfo.generated.h"

UENUM()
enum ESecretQuestion
{
	SQ_FavoriteFood UMETA(DisplayName = "FavoriteFood"),
	SQ_FavoriteFilm UMETA(DisplayName = "FavoriteFilm"),
	SQ_FavoriteSeries UMETA(DisplayName = "FavoriteSeries"),
	SQ_FavoriteMusic UMETA(DisplayName = "FavoriteMusic"),
	SQ_ChildhoodFriend UMETA(DisplayName = "ChildhoodFriend"),
	SQ_SecondSurname UMETA(DisplayName = "SecondSurname"),
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
