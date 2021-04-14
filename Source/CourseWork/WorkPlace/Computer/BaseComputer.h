// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CourseWork/WorkPlace/Persons/Person.h"
#include "GameFramework/Actor.h"
#include "BaseComputer.generated.h"

class UFileSystemAsset;
class UBasePerson;
class UBaseFileCatalogue;
class UStaticMeshComponent;

UCLASS()
class COURSEWORK_API ABaseComputer : public AActor
{
	GENERATED_BODY()

public:
	ABaseComputer();

	UFUNCTION(BlueprintCallable)
	UBaseFileCatalogue* GetFileSystem() const { return RootFileCatalogue; }

protected:
	virtual void BeginPlay() override;


private:
	UFUNCTION(BlueprintCallable)
	void SetOwnerPerson(UBasePerson* NewOwnerPerson);

	UPROPERTY()
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Monitor;

	UPROPERTY()
	UBaseFileCatalogue* RootFileCatalogue = nullptr;

	UPROPERTY(EditDefaultsOnly)
 	TSubclassOf<UBasePerson> PersonClass = nullptr;

	UPROPERTY(EditAnywhere, Category = "FileSystem")
	TSubclassOf<UFileSystemAsset> FileSystemAsset;

	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Instanced, meta = (AllowPrivateAccess = "true"), Category = "Person")
	UBasePerson* OwnerPerson = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FileSystem", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<EPosition> Position;
};
