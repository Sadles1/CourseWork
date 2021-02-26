// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FileSystem/BaseFileCatalogue.h"
#include "FileSystem/Assets/FileSystemAsset.h"

#include "GameFramework/Actor.h"
#include "BaseComputer.generated.h"

class UStaticMeshComponent;

UENUM(Blueprintable, BlueprintType)
enum EPosition
{
	Worker,
	Manager,
	Director,
	Security,
	SystemAdministrator
};


USTRUCT(BlueprintType)
struct COURSEWORK_API FPerson
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName FirstName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName MiddleName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName LastName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EPosition> Position = Worker;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDateTime BirthDate = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> UsedPasswords;
};

UCLASS()
class COURSEWORK_API ABaseComputer : public AActor
{
	GENERATED_BODY()
	
public:
	ABaseComputer();

	UFUNCTION(BlueprintCallable)
	UBaseFileCatalogue* GetFileSystem() const {return RootFileCatalogue;};

protected:
	virtual void BeginPlay() override;
	

private:

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FText Login;
	
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FText Password;

	UFUNCTION(BlueprintCallable)
	void SetOwnerPerson(const FPerson NewOwnerPerson);
	
	UPROPERTY()
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Monitor;

	UPROPERTY()
	UBaseFileCatalogue* RootFileCatalogue = nullptr;

	UPROPERTY(EditAnywhere, Category = "FileSystem")
	TSubclassOf<UFileSystemAsset> FileSystemAsset;

	UFUNCTION(BlueprintCallable)
	void SetFileSystemAsset(TSubclassOf<UFileSystemAsset> NewFileSystemAsset);

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FPerson OwnerPerson = { };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FileSystem", meta = (AllowPrivateAccess = "true"))
    TEnumAsByte<EPosition> Position;
};
