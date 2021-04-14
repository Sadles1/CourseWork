// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseComputer.h"
#include "CourseWork/WorkPlace/Persons/Person.h"
#include "FileSystem/FileSystemAsset.h"

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

	SetOwnerPerson(NewObject<UBasePerson>(this, PersonClass));
}

void ABaseComputer::SetOwnerPerson(UBasePerson* NewOwnerPerson)
{
	OwnerPerson = NewOwnerPerson;
	OwnerPerson->InitPerson(Position);
	
	if(!FileSystemAsset) return;
	
 	UFileSystemAsset* NewFileSystem = NewObject<UFileSystemAsset>(this, FileSystemAsset);
	RootFileCatalogue = NewFileSystem->GenerateFileSystem();
}