// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <Editor/UnrealEd/Classes/Editor/EditorEngine.h>
#include "BCF_Nodes.h"
#include "BCF_Files.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FBCFProjectXMLFile {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBCFProject project;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ExtensionSchema;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool shouldSerializeExtensionSchema;

};
USTRUCT(BlueprintType)
struct FBCFVersionXMLFile {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString DetailedVersion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool shouldSerializeDetailedVersion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString VersionId;
};

USTRUCT(BlueprintType)
struct FBCFMarkupXMLFile {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBCFTopic topic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBCFComment comment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBCFViewpoint viewpoint;
};

USTRUCT(BlueprintType)
struct FBCFVisualizationXMLFile {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FBCFComponent> component;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isPerspective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBCFPerspectiveCamera perspectiveCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBCFOrthogonalCamera orthogonalCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBCFBitmap bitmap;
};

USTRUCT(BlueprintType)
struct FBCFSnapshot {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* snapshotFile;
};
USTRUCT(BlueprintType)
struct FBCFTopicFile {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBCFMarkupXMLFile markupFile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBCFVisualizationXMLFile visualizationFile;
};

USTRUCT(BlueprintType)
struct FBCFMaster {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BCF")
		FBCFProjectXMLFile projectFile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BCF")
		FBCFVersionXMLFile versionFile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BCF")
		TArray<FBCFTopicFile> topicsList;
};