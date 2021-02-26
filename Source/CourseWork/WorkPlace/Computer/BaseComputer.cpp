// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseComputer.h"

ABaseComputer::ABaseComputer()
{
	SceneComponent =  CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	if(SceneComponent)
	{
		RootComponent = SceneComponent;
	}
	
	Monitor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Monitor"));
	if(Monitor)
	{
		Monitor->SetupAttachment(RootComponent);
	}
}

void ABaseComputer::BeginPlay()
{
	Super::BeginPlay();

	
}

void ABaseComputer::SetFileSystemAsset(const TSubclassOf<UFileSystemAsset> NewFileSystemAsset)
{
	FileSystemAsset = NewFileSystemAsset;
	
	if(!FileSystemAsset) return;
	
	UFileSystemAsset* NewFileSystem = NewObject<UFileSystemAsset>(this, FileSystemAsset);
	RootFileCatalogue = NewFileSystem->GenerateFileSystem();
}

void ABaseComputer::SetOwnerPerson(const FPerson NewOwnerPerson)
{
	OwnerPerson = NewOwnerPerson;

	Login = FText::FromName(OwnerPerson.FirstName);
	Password = OwnerPerson.UsedPasswords[0];
	
	if(!FileSystemAsset) return;
	
 	UFileSystemAsset* NewFileSystem = NewObject<UFileSystemAsset>(this, FileSystemAsset);
	RootFileCatalogue = NewFileSystem->GenerateFileSystem();
}