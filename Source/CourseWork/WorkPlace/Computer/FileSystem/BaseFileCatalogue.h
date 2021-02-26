// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Files/BaseFile.h"
#include "UObject/NoExportTypes.h"
#include "BaseFileCatalogue.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class COURSEWORK_API UBaseFileCatalogue : public UObject
{
	GENERATED_BODY()

public:
	UBaseFileCatalogue();

	UFUNCTION(BlueprintCallable)
	TArray<UBaseFileCatalogue*> GetChildCatalogues() const {return ChildCatalogues;}
	
	UFUNCTION(BlueprintCallable)
    TArray<UBaseFile*> GetFiles() const {return FilesInCatalogue;}
	
	UFUNCTION(BlueprintCallable)
	UBaseFileCatalogue* AddChildCatalogue(FName Name);

	UFUNCTION(BlueprintCallable)
	void AddFileToCatalogue(UBaseFile* File) {FilesInCatalogue.Add(File);}
	
private:
	void SetCatalogueName(const FName Name) {CatalogueName = Name;}
	
	UPROPERTY(BlueprintReadOnly, Category = "FileSystem", meta = (AllowPrivateAccess = "true"))
	FName CatalogueName;
	
	UPROPERTY(BlueprintReadOnly, Category = "FileSystem", meta = (AllowPrivateAccess = "true"))
	UBaseFileCatalogue* UpCatalogue;

	UPROPERTY()
	TArray<UBaseFileCatalogue*> ChildCatalogues;

	UPROPERTY()
	TArray<UBaseFile*> FilesInCatalogue;
};
