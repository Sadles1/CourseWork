// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseFileReaderWidget.h"

void UBaseFileReaderWidget::AddFile(UBaseFile* File)
{
	FileToRead = File;

	ReadFile();
}
