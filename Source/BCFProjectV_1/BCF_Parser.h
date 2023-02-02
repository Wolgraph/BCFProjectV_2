// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BCF_Nodes.h"
#include "BCF_Files.h"
#include "Misc/FileHelper.h"

#include "ZipArchive.h"
#include "ZipArchiveEntry.h"
#include "ZipFile.h"

#include "BCF_Parser.generated.h"

UCLASS(BlueprintType)
class BCFPROJECTV_1_API UBCF_Parser : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BCF")
		FBCFMaster BCFMasterProject;
	//Metodi di compilazione del testo XML
	UFUNCTION(BlueprintCallable, Category = "BCF")
		static FString FCompileProjectFile(FBCFProjectXMLFile ProjectXMLFile);
	UFUNCTION(BlueprintCallable, Category = "BCF")
		static FString FCompileVersionFile(FBCFVersionXMLFile VersionXMLFile);
	UFUNCTION(BlueprintCallable, Category = "BCF")
		static TArray<FString> FCompileTopicFiles(TArray<FBCFTopicFile> TopicList, bool PerspectiveCamera);
	UFUNCTION(BlueprintCallable, Category = "BCF")
		static FString FCompileMarkup(FBCFMarkupXMLFile Topic);
	UFUNCTION(BlueprintCallable, Category = "BCF")
		static FString FCompileVisualization(FBCFVisualizationXMLFile Topic, bool PerspectiveCamera);
	//Metodi di scrittura su file e compressione
	UFUNCTION(BlueprintCallable, Category = "BCF")
		static bool FSaveFile(FString FileStream, FString OutputPath, FString FileName, bool IsArchiveCreated);
	UFUNCTION(BlueprintCallable, Category = "BCF")
		static bool FSaveTopic(FString FileStream, FString OutputPath, FString TopicGUID, FString FileName);
	UFUNCTION(BlueprintCallable, Category = "BCF")
		static void FSaveSnapshot(FString OutputPath, FString TopicGUID, FString snapName);

};



