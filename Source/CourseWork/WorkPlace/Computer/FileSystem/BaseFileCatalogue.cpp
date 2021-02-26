// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseFileCatalogue.h"

UBaseFileCatalogue::UBaseFileCatalogue()
{
	UpCatalogue = Cast<UBaseFileCatalogue>(GetOuter());

	CatalogueName = "Root";
}

UBaseFileCatalogue* UBaseFileCatalogue::AddChildCatalogue(const FName Name)
{
	UBaseFileCatalogue* NewChildCatalogue = NewObject<UBaseFileCatalogue>(this);
	NewChildCatalogue->SetCatalogueName(Name);

	ChildCatalogues.Add(NewChildCatalogue);

	return NewChildCatalogue;
}

