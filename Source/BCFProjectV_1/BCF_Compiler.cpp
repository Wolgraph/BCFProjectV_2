// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BCF_Compiler.h"

//#include "BCG_Compiler.generated.h"


FString UBCF_Compiler::FMYStringPrint()
{
	std::string ArchiveName = "Archivio.bcf";
	FString FSavePath = FPaths::ProjectDir() + "OutputFiles/";
	std::string SavePath=TCHAR_TO_UTF8(*FSavePath) + ArchiveName;
	ZipArchive::Ptr Archive = ZipFile::Open(ArchiveName);
	ZipFile::SaveAndClose(Archive, SavePath);
	return (FSavePath);
}
