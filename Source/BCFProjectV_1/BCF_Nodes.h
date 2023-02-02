// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BCF_Nodes.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FBCFBitmap {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString bitmap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString reference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector normal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector upvector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector height;
};
USTRUCT(BlueprintType)
struct FBCFComment {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString CommentGUID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString CreationDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString CreationAuthor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Comment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Viewpoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ModifiedDate;;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ModifiedAuthor;
};
USTRUCT(BlueprintType)
struct FBCFComponent {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString color;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ifcGUID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString OriginatingSystem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString AuthoingTool;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool visible;
};
USTRUCT(BlueprintType)
struct FBCFFile {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString IfcProject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString IfcSpatialstructureElement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Reference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FDateTime Date;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Filename;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsExternal;
};
USTRUCT(BlueprintType)
struct FBCFHeader {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FBCFFile> Files;
};
USTRUCT(BlueprintType)
struct FBCFLine {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Start;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector End;
};
USTRUCT(BlueprintType)
struct FBCFOrthogonalCamera {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector upVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float viewScale;
};
USTRUCT(BlueprintType)
struct FBCFPerspectiveCamera {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector upVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float fieldOfView;
};
USTRUCT(BlueprintType)
struct FBCFProject {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ProjectID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool shouldSerializeProjectID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool shouldSerializeName;
};
USTRUCT(BlueprintType)
struct FBCFTopic {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString TopicGUID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString TopicType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ReferenceLink;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Priority;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString CreationDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString CreationAuthor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ModifiedDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ModifiedAuthor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString AssignTo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString TopicStatus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString DueDate;
};
USTRUCT(BlueprintType)
struct FBCFViewpoint {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ViewpointGUID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString viewpoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString snapshot;
};
